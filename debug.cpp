struct error {
    template<class T1, class T2> error& operator << (pair<T1, T2> a) {
        return *this << "(" << a.first << ", " << a.second << ")";
    }

    template<class T> typename enable_if<is_scalar<T>::value || is_same<T,string>::value, error&>::type operator << (T a) {
        cerr << boolalpha << a;
        return *this;
    }

    template<class T> typename enable_if<!is_scalar<T>::value && !is_same<T, string>::value, error&>::type operator << (T a) {
        *this << "{";
        for (auto i = a.begin(); i != a.end(); ++i)
            *this << ", " + 2 * (i == a.begin()) << *i;
        return *this << "}";
    }
};

#define err error()


