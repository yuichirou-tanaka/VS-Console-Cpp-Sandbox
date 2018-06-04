#include <stdio.h>
#include <array>
#include <memory>

using namespace std;

class TestA {
public:
	float b[2];

	TestA()
		:b{ 0.15f, 0.2f }
	{

	}
};
class TestAB {
public:
	std::array<float, 2> bs;
	TestAB()
		:bs{ 0.15f, 0.2f }
	{
		print();
		printf("TestAB const \n");
	}
	~TestAB()
	{
		print();
		printf("TestAB destrouctor \n");

	}
	void print()
	{
		printf("%f %f \n", bs[0], bs[1]);
	}
};
class UniqueCreate {
public:
	UniqueCreate(std::unique_ptr<TestAB> testb)
		: mtestb(move(testb))
	{

	}
	std::unique_ptr<TestAB> create() {
		mtestb = std::unique_ptr<TestAB>(new TestAB());
		mtestb->bs[0] = 0.9f;
		mtestb->bs[1] = 2.9f;
		mtestb->print();
		return move(mtestb);
	}
	std::unique_ptr<TestAB> mtestb;
};

void main() {
	printf("test\n");
	{
		printf("1\n");
		std::unique_ptr<TestAB> tb;
		printf("2\n");
		//std::unique_ptr<TestAB>* tbp;
		UniqueCreate uc(move(tb));
		printf("3\n");
		tb = uc.create();
		printf("4\n");
		tb->print();
		tb->bs[0] = 12;
		tb->bs[1] = 13;
		tb->print();
		printf("%f %f \n", tb->bs[0], tb->bs[1]);
	}


	

}