#include<iostream>
#include<string>
#include<fstream>

std::ifstream information("animal.txt");
std::ofstream myfile;


class animal
{
public:
	virtual void cry() {}
};
class Cow :public animal
{
public:
	void cry()
	{
		std::cout << "Cow         " <<"Mooo" << std::endl;
	}
};
class Duck :public animal
{
public:
	void cry()
	{
		std::cout << "Duck        " << "Quack!, quack!" << std::endl;
	}
};

class Dog :public animal
{
public:
	void cry()
	{
		std::cout <<" Dog        " << "Bow, bow" << std::endl;

		myfile.open("output.txt", std::ios_base::app);
		myfile  << " Dog        " << "Bow, bow" << std::endl;
		/*myfile << test->cry();*/
		myfile.close();


		myfile.open("output.txt", std::ios_base::app);
		myfile << "Data";


	}
};

animal* get_cry(const std::string &name)
{
	if (name == "Dog")
		return new Dog;

	else if (name == "Duck")
		return new Duck;

	else if (name == "Cow")
		return new Cow;

	else return nullptr;
}

int main()
{
	animal* test;
	char buffer[100];



	


	if (!information.is_open())
	{
		std::cout << "no file";
		
		
		std::cout << " ";
		std::cout << " ";
		return 0;
	}

	else
	{
		while (!information.eof())
		{
			information.getline(buffer, 100);
			test = get_cry(buffer);
			test->cry();


			
			

		/*	std::ofstream outfile;

			outfile.open("test.txt", std::ios_base::app);
			outfile << "Data";*/

		}
		delete test;
	}

	return 0;
}