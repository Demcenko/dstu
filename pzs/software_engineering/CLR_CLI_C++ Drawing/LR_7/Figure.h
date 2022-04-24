#pragma once
class Figure
{
	int length; 
public:
	void SetLength(int a)
	{
		length = a; 
	}
	int GetLength()
	{
		return length;
	}
};

class Square : public Figure		//������� 
{
public: 
	void SetLength(int a)
	{
		Figure::SetLength(a);
	}
	int GetLength()
	{
		return Figure::GetLength();
	}
};
class RectangleClass: public Square		//�������������
{
	int width; 
public:
	void SetWidth(int a)
	{
		width=a; 
	}
	void SetLength(int a)
	{
		Square::SetLength(a);
	}
	int GetWidth()
	{
		return width;
	}
	int GetLength()
	{
		return Square::GetLength();
	}
}; 

class Circle: public Figure			//����
{
public: 
	void SetRadius(int a)
	{
		Figure::SetLength(a);
	}
	int GetRadius()
	{
		return Figure::GetLength();
	}
};

class Equilateral: public Figure	//�������������� �����������
{ 
public: 
	void SetLength(int a)
	{
		Figure::SetLength(a);
	}
	int GetLength()
	{
		return Figure::GetLength();
	}
}; 

class Isosceles: public Equilateral		//��������������
{
public:
	void SetLength(int a)
	{
		Equilateral::SetLength(a);
	}
	int GetLength()
	{
		return Equilateral::GetLength();
	}
};
class Rectangular: public Equilateral		//�������������
{
	int width; 
public:
	void SetWidth(int a)
	{
		width=a; 
	}
	void SetLength(int a)
	{
		Equilateral::SetLength(a);
	}
	int GetWidth()
	{
		return width;
	}
	int GetLength()
	{
		return Equilateral::GetLength();
	}
}; 

