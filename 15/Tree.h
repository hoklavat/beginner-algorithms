#ifndef Tree_h
#define Tree_h

template <typename t_Data>
class Tree{
public:
	virtual void traversal() const = 0;
	virtual void insert(const t_Data &data) = 0;
	virtual void remove(const t_Data &data) = 0;
	virtual const t_Data &getMaxValue() const = 0;
	virtual const t_Data &getMinValue() const = 0;
};

#endif