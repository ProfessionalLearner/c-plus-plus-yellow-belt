#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date)
: comparison_(cmp),
date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch(comparison_) {
	case Comparison::Less:
		return date < date_;
		break;
	case Comparison::LessOrEqual:
		return date <= date_;
		break;
	case Comparison::Greater:
		return date > date_;
		break;
	case Comparison::GreaterOrEqual:
		return date >= date_;
		break;
	case Comparison::Equal:
		return date == date_;
		break;
	case Comparison::NotEqual:
		return date != date_;
		break;
	}
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event)
: comparison_(cmp),
event_(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch(comparison_) {
	case Comparison::Less:
		return event < event_;
		break;
	case Comparison::LessOrEqual:
		return event <= event_;
		break;
	case Comparison::Greater:
		return event > event_;
		break;
	case Comparison::GreaterOrEqual:
		return event >= event_;
		break;
	case Comparison::Equal:
		return event == event_;
		break;
	case Comparison::NotEqual:
		return event != event_;
		break;
	}
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& operation,
		const shared_ptr<Node> left, const shared_ptr<Node> right)
		: operation_(operation),
		left_(left),
		right_(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch(operation_) {
	case LogicalOperation::Or:
		return left_->Evaluate(date, event) || right_->Evaluate(date, event);
		break;
	case LogicalOperation::And:
		return left_->Evaluate(date, event) && right_->Evaluate(date, event);
		break;
	}
}
