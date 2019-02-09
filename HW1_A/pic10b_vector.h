#include <iostream>   // std::ostream, std::cout
#include <string>
namespace Pic10b {

	template <class T>

	class vector {
	private:
		T* the_data;
		size_t the_size;
		size_t the_capacity;

		static const int INIT_CAP = 10;


	public:
		// The big 4 
		vector() :the_data(nullptr), the_size(0), the_capacity(INIT_CAP) {
			std::cout << "********* DEFAULT CONSTRUCTOR CALLED"<<std::endl;
			the_data = new T[the_capacity];
		}

		vector(const vector& source) :the_data(nullptr), the_size(source.the_size), the_capacity(source.the_capacity) {
			std::cout << "********* COPY CONSTRUCTOR CALLED"<<std::endl;
			
			the_data = new T[the_capacity];
			// Deep copy of internal array
			for (int i = 0; i < the_size; ++i) {
				the_data[i] = source.the_data[i];
			}
		}
		vector& operator=(const vector& rhs) {
			std::cout << "********* ASSIGNMENT OPERATOR CALLED"<<std::endl;
			if (this != &rhs) {     // Self-assignment?
				// Release old memory and request more 
				delete[] the_data;
				the_data = new T[rhs.the_capacity];

				// Shallow copy non-pointers
				the_size = rhs.the_size;
				the_capacity = rhs.the_capacity;

				// Deep copy internal array
				for (int i = 0; i < the_size; ++i)
					the_data[i] = rhs.the_data[i];
			}
			return *this;
		}
//this function is the destructor
		~vector() {
			std::cout << "********* DESTRUCTOR CONSTRUCTOR CALLED"<<std::endl;
			delete[] the_data;
		}

		vector& operator+= (const vector& rhs) {
			if (this->size() != rhs.size())
			{
				return *this;
			}
			for (int i = 0; i < this->size(); ++i) {
					this->the_data[i] += rhs.the_data[i];
				}
			return *this;
		}
//this is the operator plus that operator on the element 
		vector operator+ (const vector &rhs) const {
			vector out(*this);

			return out+=rhs ;
		}

		// the operator to deal with left vector right scalar
		vector operator* (const T& scalar)  const{
			vector out(*this);
			for (int i = 0; i < this->size(); ++i) {
				out.the_data[i] *= scalar;
			}
			return out;
		}
		


		// Other members [public]
		bool empty() const { return the_size == 0; }
		size_t size() const { return the_size; }
		size_t capacity() const { return the_capacity; }
	        
                // this is how you set up the template 
		T front() const { return *the_data; }
		T back() const { return *(the_data + the_size - 1); }
		T at(size_t index) const {
			if (index < the_size)
				return the_data[index];
			return the_data[0];
		}
		// why is there 2 of this??


		T& operator[](size_t index) { return the_data[index]; }
		T operator[](size_t index) const{return the_data[index];}
		void dump_data_to(std::ostream& out) const {
			out << "Vector (dump): ";
			for (size_t i = 0; i < the_capacity; ++i)
				out << the_data[i] << ' ';
			out << '\n';
		}
		void dump_data() const {dump_data_to(std::cout);}
		void push_back(T new_value) {
			if (the_size == the_capacity)
				reserve(the_capacity + 1);     // `the_data` is reassigned

			the_data[the_size++] = new_value;
		}
		void pop_back(){
			if (the_size > 0)
				--the_size; }

	private:
		//Other members [private]
		void reserve(size_t new_capacity) {
			if (new_capacity > the_capacity) {
				if (new_capacity <= 2 * the_capacity)
					new_capacity = 2 * the_capacity;

				T* old_location = the_data;

				the_data = new T[new_capacity];
				the_capacity = new_capacity;

				for (size_t i = 0; i < the_size; ++i)
					the_data[i] = old_location[i];

				delete old_location;
			}
		}

	}; // end Pic10b::vector





} // end Pic10b namespace



/** ************************ OTHER FUNCTIONS ************************ **/

template <class T>
std::ostream& operator<<(std::ostream& out, const Pic10b::vector<T>& v) {
	for (size_t i = 0; i < v.size(); ++i)
		out << v[i] << ' ';
	return out;
}

template <class T>
void print_vector(const Pic10b::vector<T>& v) {
	if (v.empty())
		std::cout << "Vector is empty\n";
	else
		std::cout << "Vector (contents): " << v << '\n';
}


// the operator to deal with the left scalar right vector
// this is not a memember function, it returns a object type vecotr<T>
// you cannot access the member function of T, so just do this to overload the operator.
template <class T>
Pic10b::vector<T> operator*(const T& scalar, const Pic10b::vector<T>& v ) {
	return v * scalar; 
}



// this is the sepicilization of the nonmember function
// but notice that out[i] had to be initialize if you want it to work
// because if it is not initialized the complier automatically become not predictable
template <>
Pic10b::vector<std::string> operator*(const std::string& prefix, const Pic10b::vector<std::string>& v) {
	Pic10b::vector<std::string> out(v);
	for (size_t i = 0; i < v.size(); ++i) {
		out[i] = "";
		out[i].append(prefix);
		out[i].append(" ");
		out[i].append(v[i]);
	}
	return out;
}

template <class T>
T operator*(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	// vector<T> out will of course give you error, because the name is Pic10b::vector<T> out
	T out=0;
	for (size_t i = 0; i < a.size(); ++i) {
		out= out +a[i] * b[i];
	}
	return out;
}



template <class T>
bool operator<(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	return sqrt(a*a)<sqrt(b*b);
}

template <class T>
bool operator<=(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	return sqrt(a*a) <= sqrt(b*b);
}

template <class T>
bool operator>(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	return sqrt(a*a) > sqrt(b*b);
}

template <class T>
bool operator>=(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	return sqrt(a*a) >= sqrt(b*b);
}

template <class T>
bool operator==(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	return sqrt(a*a) == sqrt(b*b);
}

template <>
bool operator ==(const Pic10b::vector<std::string>& a, const Pic10b::vector<std::string>& b) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i]!=b[i]) {
			return false;
		}
	}
	return true;
}




template <class T>
bool operator!=(const Pic10b::vector<T>& a, const Pic10b::vector<T>& b) {
	return sqrt(a*a) != sqrt(b*b);
}


template <>
bool operator !=(const Pic10b::vector<std::string>& a, const Pic10b::vector<std::string>& b) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			return true;
		}
	}
	return false;
}

/*
template <class T>
T sqrt(const T a) {
	return sqrt(a);
}
*/

// specilization of member function
template <>
Pic10b::vector<std::string> Pic10b::vector<std::string>::operator* (const std::string& postfix)  const {
	vector <std::string> out(*this);
	for (size_t i = 0; i < this->size(); ++i) {
		out[i] = "";
		out[i].append(this->the_data[i]);		
		out[i].append(" ");
		out[i].append(postfix);
	}
	return out;
}

//specilization of nonmember function

/*
template <>
T operator*(const std::string & a, const Pic10b::vector<std::string>& b) {
	Pic10b::vector <std::string> out ;

	for (size_t i = 0; i < b.size(); ++i) {
		out[i].append(b[i]);
		out[i].append(" ");
		out[i].append(a);
		std::cout << out[i];
	}
	return out;
}
*/
