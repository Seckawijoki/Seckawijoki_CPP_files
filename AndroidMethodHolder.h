#ifndef ANDROID_METHOD_HOLDER_H
#define ANDROID_METHOD_HOLDER_H
#include <vector>
using namespace std;
namespace lua2java {
	enum Type {
		JAVA_VOID = 0,
		JAVA_BOOLEAN,
		JAVA_BYTE,
		JAVA_CHAR,
		JAVA_SHORT,
		JAVA_INT,
		JAVA_LONG,
		JAVA_FLOAT,
		JAVA_DOUBLE,
		JAVA_STRING,
		//JAVA_OBJECT,
		//JAVA_BOOLEAN_ARRAY,
		//JAVA_BYTE_ARRAY,
		//JAVA_CHAR_ARRAY,
		//JAVA_SHORT_ARRAY,
		//JAVA_INT_ARRAY,
		//JAVA_LONG_ARRAY,
		//JAVA_FLOAT_ARRAY,
		//JAVA_DOUBLE_ARRAY,
		//JAVA_OBJECT_ARRAY,
		//JAVA_STRING_ARRAY,
	};
	class Holder {
	public:
		Holder() : m_Type(JAVA_VOID) {

		}
		Holder(Type type) : m_Type(type) {

		}
		template <typename T> Holder(Type type, T const& value) : m_Type(type), ptr_(new Data<T>(value)) {

		}
		Holder(Holder const& other) : m_Type(other.m_Type) {
			if (other.ptr_) {
				ptr_ = other.ptr_->clone();
			}
		}
		Holder& operator = (Holder const& other) {
			Holder(other).swap(*this);
			return *this;
		}
		~Holder() {
			delete this->ptr_;
		}
		void swap(Holder& other) {
			Base* temp = this->ptr_;
			this->ptr_ = other.ptr_;
			other.ptr_ = temp;
		}
		template <typename T> T& get() {
			return dynamic_cast<Data<T>&>(*this->ptr_).value_;
		}
		Type getType() {
			return m_Type;
		}
	private:
		struct Base {
			virtual ~Base() {

			}
			virtual Base* clone() const = 0;
		};
		template <typename T>
		struct Data : Base {
			Data(T const& value) : value_(value) {

			}
			Base* clone() const {
				return new Data<T>(*this);
			}
			T value_;
		};
		Base* ptr_;
		Type m_Type;
	};
}
#endif