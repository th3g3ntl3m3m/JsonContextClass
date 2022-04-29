template<class T>
Value<T>::Value()
{
}

template<class T>
Value<T>::~Value()
{
}

template<class T>
Value<T>& Value<T>::operator= (T val)
{
	data = val;
	return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Value<T>& val)
{
	out << val.data;
	return out;
}