#pragma once
class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual int GetAge() const = 0;
};
