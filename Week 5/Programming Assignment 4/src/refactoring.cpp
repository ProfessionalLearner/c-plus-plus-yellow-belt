#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Person {
public:
	Person(const string& name, const string& occupation)
	: Name(name),
	Occupation(occupation) {
	}

	virtual void Walk(const string& destination) const = 0;

	string GetName() const {
		return Name;
	}

	string GetOccupation() const {
		return Occupation;
	}
private:
	const string Name;
	const string Occupation;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong)
	: Person(name, "Student"),
	FavouriteSong(favouriteSong) {
    }

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject)
	: Person(name, "Teacher"),
	Subject(subject) {
    }

    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name)
	: Person(name, "Policeman") {
    }

    void Check(const Person& person) const {
        cout << "Policeman: " << GetName() << " checks "
        	 << person.GetOccupation() <<  ". "
			 << person.GetOccupation() << "'s name is: " << person.GetName() << endl;
    }


    void Walk(const string& destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }
};

void VisitPlaces(const Person& person, const vector<string>& places) {
	for(const auto& p : places) {
		person.Walk(p);
	}
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}*/
class People{
public:
	People(const string &s, const string &w ):Name(s), who(w){}
    virtual void Walk( const string& destination)=0;
public:
    const string Name="unknown";
    const string who="Person";
};
class Student: public People{
public:
    Student(const string& name, const string& favouriteSong):
	People(name, "Student"), FavouriteSong(favouriteSong) {


    }
    void Learn() const{
        cout << "Student: " << Name << " learns" << endl;
    }

    virtual void Walk( const string& destination) override  {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher: public People {
public:

    Teacher(const string& name, const string& subject) :
	People(name, "Teacher"), Subject (subject)
{
    }

    void Teach() const {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }
	virtual void Walk(const string& destination) override {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

public:
    const string Subject;
};


class Policeman :public People {
public:
    Policeman(const string& name):
	People(name, "Policeman") {
    }

    void Check ( const People& p) const {
        cout << "Policeman: " << Name << " checks "<< p.who<<". "<<p.who<<  "'s name is: " << p.Name << endl;
    }

    void Walk(const string& destination) override {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }


};


void VisitPlaces(People& t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}



int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}



