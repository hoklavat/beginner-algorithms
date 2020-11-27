#pragma once

template<class t_Data>
class List{
public:
	virtual void insert(const t_Data &data) = 0;
	virtual void remove(const t_Data &datat) = 0;
	virtual void traverseList() const = 0;
	virtual int size() const = 0;
};