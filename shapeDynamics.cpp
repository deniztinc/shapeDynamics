#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <forward_list>
using namespace std;

class SHAPE
{
private:
	string color;
	static int count;
public:
	SHAPE();
	SHAPE(const string&);
	SHAPE(const SHAPE&);
	virtual ~SHAPE();
	string getColor() const;
	static int getCount();
	void setColor(const string&);
	virtual string getName() const = 0;
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void printShapeInfo(ostream&) const = 0;
	virtual void readShapeInfo(istream&) = 0;
	friend ostream& operator << (ostream&, const SHAPE&);
	friend istream& operator >> (istream&, SHAPE&);
};
typedef SHAPE* ShapePtr;
int SHAPE::count = 0;

SHAPE::SHAPE()
{
	color = "None";
	count++;
}
SHAPE::SHAPE(const string& clr)
{
	color = clr;
	count++;
}
SHAPE::SHAPE(const SHAPE& s)
{
	color = s.color;
	count++;
}
SHAPE::~SHAPE()
{
	count--;
}

string SHAPE::getColor() const
{
	return color;
}
int SHAPE::getCount()
{
	return count;
}

void SHAPE::setColor(const string& clr)
{
	color = clr;
}

string SHAPE::getName() const
{
	return "SHAPE";
}

double SHAPE::getArea() const
{
	return 0;
}

double SHAPE::getPerimeter() const
{
	return 0;
}

ostream& operator << (ostream& out, const SHAPE& s)
{
	out.setf(ios::fixed | ios::left);	//Left aligned fixed decimal places
	s.printShapeInfo(out);
	out.unsetf(ios::fixed | ios::left);//Removing formatting
	cout.precision(0);			//Resetting the decimal places
	return out;
}
istream& operator >> (istream& in, SHAPE& s)
{
	s.readShapeInfo(in);
	return in;
}

class RECTANGLE : public SHAPE
{
private:
	double length, width;
public:
	RECTANGLE();
	RECTANGLE(const double& len, const double& wid, const string& clr);
	RECTANGLE(const RECTANGLE&);
	double getLength() const;
	double getWidth() const;
	void setLength(const double&);
	void setWidth(const double&);
	virtual string getName() const;
	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual void printShapeInfo(ostream&) const;
	virtual void readShapeInfo(istream&);
};

RECTANGLE::RECTANGLE() : SHAPE()
{
	length = 0;
	width = 0;
}
RECTANGLE::RECTANGLE(const double& len, const double& wid, const string& clr) : SHAPE(clr)
{
	length = len;
	width = wid;
}
RECTANGLE :: RECTANGLE(const RECTANGLE& r) : SHAPE(r.getColor())
{
	length = r.length;
	width = r.width;
}

double RECTANGLE::getLength() const
{
	return this->length;
}

double RECTANGLE::getWidth() const
{
	return this->width;
}

void RECTANGLE::setLength(const double& len)
{
	this->length = len;
}

void RECTANGLE::setWidth(const double& wid)
{
	this->width = wid;
}

double RECTANGLE::getArea() const
{
	return this->length*this->width;
}

double RECTANGLE::getPerimeter() const
{
	return (2*this->width)+(2*this->length);
}

string RECTANGLE::getName() const
{
	return "Rec";
}
void RECTANGLE::printShapeInfo(ostream& out) const
{
	out << setw(11) << getName() + " " + getColor();
	out << "Area = " << setw(9) << setprecision(2) << getArea();
	out << "Perimeter = " << setw(9) << setprecision(2) << getPerimeter();
	out << "Length = " << setw(7) << setprecision(2) << length;
	out << "Width = " << setw(5) << setprecision(2) << width;
}
void RECTANGLE::readShapeInfo(istream& in)
{
	cout << "\tEnter length ";
	in >> length;
	cout << "\tEnter width ";
	in >> width;
	string temp;
	cout << "\tEnter color ";
	in >> temp;
	setColor(temp);
}

class TRIANGLE : public SHAPE
{
private:
	double base, height;
public:
	TRIANGLE();
	TRIANGLE(const double& b, const double& h, const string& clr);
	TRIANGLE(const TRIANGLE&);
	double getBase() const;
	double getHeight() const;
	void setBase(const double&);
	void setHeight(const double&);
	virtual string getName() const;
	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual void printShapeInfo(ostream&) const;
	virtual void readShapeInfo(istream&);
};
/////////////////////////////////////////////////////////////////////////////////////
TRIANGLE::TRIANGLE() : SHAPE()
{
	base = 0;
	height = 0;
}
TRIANGLE::TRIANGLE(const double& b, const double& h, const string& clr) : SHAPE(clr)
{
	base = b;
	height = h;
}
TRIANGLE :: TRIANGLE(const TRIANGLE& t) : SHAPE(t.getColor())
{
	base = t.base;
	height = t.height;
}

double TRIANGLE::getBase() const
{
	return this->base;
}

double TRIANGLE::getHeight() const
{
	return this->height;
}

void TRIANGLE::setBase(const double& bas) 
{
	this->base = bas;
}

void TRIANGLE::setHeight(const double& hei)
{
	this->height = hei;
}

double TRIANGLE::getArea() const
{
	return (this->height*this->base)/2;
}

double TRIANGLE::getPerimeter() const
{
	double hypotenuse;
	hypotenuse = sqrt((this->base*this->base)+(this->height*this->height));
	return hypotenuse+this->base+this->height;
}

string TRIANGLE::getName() const
{
	return "Tri";
}
void TRIANGLE::printShapeInfo(ostream& out) const
{
	out << setw(11) << getName() + " " + getColor();
	out << "Area = " << setw(9) << setprecision(2) << getArea();
	out << "Perimeter = " << setw(9) << setprecision(2) << getPerimeter();
	out << "Base = " << setw(9) << setprecision(2) << base;
	out << "Height = " << setw(5) << setprecision(2) << height;
}
void TRIANGLE::readShapeInfo(istream& in)
{
	cout << "\tEnter base ";
	in >> base;
	cout << "\tEnter height ";
	in >> height;
	string temp;
	cout << "\tEnter color ";
	in >> temp;
	setColor(temp);
}

class CIRCLE : public SHAPE
{
private:
	double radius;
public:
	CIRCLE();
	CIRCLE(const double& r, const string& clr);
	CIRCLE(const CIRCLE&);
	double getRadius() const;
	void setRadius(const double&);
	virtual string getName() const;
	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual void printShapeInfo(ostream&) const;
	virtual void readShapeInfo(istream&);
};

CIRCLE::CIRCLE() : SHAPE()
{
	radius = 0;
}
CIRCLE::CIRCLE(const double& r, const string& clr) : SHAPE(clr)
{
	radius = r;
}
CIRCLE :: CIRCLE(const CIRCLE& c) : SHAPE(c.getColor())
{
	radius = c.radius;
}

double CIRCLE::getRadius() const
{
	return this->radius;
}

void CIRCLE::setRadius(const double& rad)
{
	this->radius = rad;
}

double CIRCLE::getArea() const
{
	return (this->radius*this->radius*3.14);
}

double CIRCLE::getPerimeter() const
{
	return (2*3.14*this->radius);
}

string CIRCLE::getName() const
{
	return "Cir";
}
void CIRCLE::printShapeInfo(ostream& out) const
{
	out << setw(11) << getName() + " " + getColor();
	out << "Area = " << setw(9) << setprecision(2) << getArea();
	out << "Perimeter = " << setw(9) << setprecision(2) << getPerimeter();
	out << "Radius = " << setw(7) << setprecision(2) << radius;
}
void CIRCLE::readShapeInfo(istream& in)
{
	cout << "\tEnter radius ";
	in >> radius;
	string temp;
	cout << "\tEnter color ";
	in >> temp;
	setColor(temp);
}

class SQUARE : public RECTANGLE
{
public:
	SQUARE();
	SQUARE(const double&, const string&);
	SQUARE(const SQUARE&);
	double getSide() const;
	void setLength(const double&);
	void setWidth(const double&);
	void setSide(const double&);
	virtual string getName() const;
	virtual void printShapeInfo(ostream&) const;
	virtual void readShapeInfo(istream&);
};

SQUARE::SQUARE() : RECTANGLE()
{
}
SQUARE::SQUARE(const double& s, const string& clr) : RECTANGLE(s, s, clr)
{
}
SQUARE :: SQUARE(const SQUARE& s) : RECTANGLE(s)
{
}

double SQUARE::getSide() const 
{
	return this->getWidth();
}

void SQUARE::setLength(const double& len)
{
	setSide(len);
}

void SQUARE::setWidth(const double& wid) 
{
	setSide(wid);
}

void SQUARE::setSide(const double& len) 
{
	RECTANGLE::setWidth(len);
	RECTANGLE::setLength(len);
}

string SQUARE::getName() const
{
	return "Sqr";
}
void SQUARE::printShapeInfo(ostream& out) const
{
	out << setw(11) << getName() + " " + getColor();
	out << "Area = " << setw(9) << setprecision(2) << getArea();
	out << "Perimeter = " << setw(9) << setprecision(2) << getPerimeter();
	out << "Side = " << setw(9) << setprecision(2) << getLength();
}
void SQUARE::readShapeInfo(istream& in)
{
	double side;
	cout << "\tEnter side ";
	in >> side;
	setSide(side);
	string temp;
	cout << "\tEnter color ";
	in >> temp;
	setColor(temp);
}

ShapePtr getRandomShape()
{
	string ColorArray[] = {"Red", "White", "Green", "Yellow", "Black", "Orange", "Brown", "Grey", "Purple", "Blue"};
	int r = rand() % 4;
	if (r == 0)
		return new RECTANGLE(rand()%15+1, rand()%15+1, ColorArray[rand()%10]);
	else if (r == 1)
		return new TRIANGLE(rand()%15+1, rand()%15+1, ColorArray[rand()%10]);
	else if (r == 2)
		return new CIRCLE(rand()%15+1, ColorArray[rand()%10]);
	else
		return new SQUARE(rand()%15+1, ColorArray[rand()%10]);
}

void print_forward_list(forward_list<ShapePtr> &s)
{
	for (forward_list<ShapePtr>::iterator it = s.begin(); it != s.end(); it++)
	cout << *it << " ";
	cout << endl;
	return;
}

void delete_forward_list(forward_list<ShapePtr> &s)
{
	forward_list<ShapePtr>::iterator it = s.begin();
	while(it != s.end())
	{
		delete *it;
		it++;
	}
	s.clear();
	return;
}

void insert_grouped(forward_list<ShapePtr> &a, ShapePtr &value)
{
	if (a.empty() == true)
		a.push_front(value);
	else
	{
		forward_list<ShapePtr>::iterator it1 = a.before_begin(), it2 = a.begin();
		while (it2 != a.end())
		{
			if ((*it2)->getName() == value->getName())
			{
				if((*it2)->getArea() <= value->getArea())
				{
					ShapePtr temp = *it2;
					*it2 = value;
					value = temp;
					it2++;
				}
				break;
			}
			it1++;
			it2++;
		}
		a.insert_after(it1, value);
	}
}
	
void insert_grouped_sorted(forward_list<ShapePtr> &a, ShapePtr &p)
{
	if(a.empty() == true)
		a.push_front(p);
	else
	{
		forward_list<ShapePtr>::iterator it1 = a.before_begin(), it2 = a.begin();
		while(it2 != a.end())
		{
			if(( *it2)->getName() == p->getName())
			{
				if((*it2)->getArea() <= p->getArea())
				{
					ShapePtr temp = *it2;
					*it2 = p;
					p = temp;
					it2++;
				}
				break;
			}
			it1++;
			it2++;
		}
		a.insert_after(it1, p);
	}
}

int main()
{
	//Let us use the same seed in order to generate the same random numbers on all the lab computers 
	//that use the same version of MSVC++. This way the output of this program on any of the lab 
	//computers will be identical to the output provided below so long as your implementations are 
	//correct.	
	unsigned int seed = 5;
	srand(seed);
	const int SIZE = 20;

	//Print the number of objects at the beginning
	cout << "At the start there are " << SHAPE::getCount() << " objects in our application." << endl;

	//Declare a forward_list container of pointers to SHAPE objects
	forward_list<ShapePtr> S;

	///////////////////////////////////// TASK 2.1 ///////////////////////////////////////////////////////
	cout << "*****************************************************************************" << endl;
	//Insert SIZE random objects into the container using push_front member function
	//This is already provided by a member function so there is no much for us to do
	for (int i = 0; i < SIZE; i++)
	{
		ShapePtr p = getRandomShape();
		cout << "Inserting " << endl << *p << endl;
		S.push_front(p);
	}

	//Print the number of objects constructed so far
	cout << endl << "Now there are " << SHAPE::getCount() << " objects constructed." << endl << endl;

	//Print the elements of the container
	cout << "The elements of the forward_list container are" << endl;
	print_forward_list(S);

	//Now delete all the elements of the forward_list
	delete_forward_list(S);
	
	//Print the number of objects we now still have
	cout << endl << "Now there are " << SHAPE::getCount() << " objects in the container." << endl << endl;
	
	///////////////////////////////////// TASK 2.2 ///////////////////////////////////////////////////////
	cout << "*****************************************************************************" << endl;
	
//Insert SIZE random objects into the container using insert_grouped non-member function
	for (int i = 0; i < SIZE; i++)
	{
		ShapePtr p = getRandomShape();
		cout << "Inserting " << endl << *p << endl;
		insert_grouped(S, p);
	}

	//Print the number of objects constructed so far
	cout << endl << "Now there are " << SHAPE::getCount() << " objects constructed." << endl << endl;

	//Print the elements of the container
	cout << "The elements of the forward_list container are" << endl;
	print_forward_list(S);

	//Now delete all the elements of the forward_list
	delete_forward_list(S);
	
	//Print the number of objects we now still have
	cout << endl << "Now there are " << SHAPE::getCount() << " objects in the container." << endl << endl;
	
	///////////////////////////////////// TASK 2.3 ///////////////////////////////////////////////////////
	cout << "*****************************************************************************" << endl;
	//Insert SIZE random objects into the container using insert_grouped_sorted non-member function
	for (int i = 0; i < SIZE; i++)
	{
		ShapePtr p = getRandomShape();
		cout << "Inserting " << endl << *p << endl;
		insert_grouped_sorted(S, p);
	}

	//Print the number of objects constructed so far
	cout << endl << "Now there are " << SHAPE::getCount() << " objects constructed." << endl << endl;

	//Print the elements of the container
	cout << "The elements of the forward_list container are" << endl;
	print_forward_list(S);

	//Now delete all the elements of the forward_list
	delete_forward_list(S);
	
	//Print the number of objects we now still have
	cout << endl << "Now there are " << SHAPE::getCount() << " objects in the container." << endl << endl;

	system("Pause");
	return 0;
}


