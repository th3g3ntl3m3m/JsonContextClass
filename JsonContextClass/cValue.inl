Value::Value()
{
}

Value::~Value()
{
}

Value& Value::operator= (int val)
{
	data = val;
	return *this;
}

std::ostream& Context::operator<<(std::ostream& out, const Value& val)
{
	out << val.data;
	return out;
}