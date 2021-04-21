/* TODO: needs improvement */
/* multiple integers */
template<typename T> 
void print(T a) { 
    cerr << a << endl;
}
template<typename T, typename T0> 
void print(T a, T0 b){ 
    cerr << a << ", " << b << endl;
}
template<typename T, typename T0, typename T1> 
void print(T a, T0 b, T1 c){ 
    cerr << a << ", " << b << ", " << c << endl;
}
template<typename T, typename T0, typename T1, typename T2> 
void print(T a, T0 b, T1 c, T2 d){ 
    cerr << a << ", " << b << ", " << c << ", " << d << endl;
}

/* pair */
template<typename T, typename T0> 
void print(pair<T,T0> x){ 
    cerr << "[ " << x.ff << ", " << x.ss << " ]\n";
}

/* std::array */
/* TODO: change size according to declaration in program */
template<typename T> 
void print(const array<T, 3> a){ 
    int z = 0;
    cerr << "[ ";
    while(z < 3) {
        cerr << a[z++] << " ";
    }
    cerr << "]";
}

/* vectors */
template<typename T> 
void print(const vector<T> a){ 
    cerr << "[ ";
    for(auto it = a.begin(); it!=a.end(); it++) {
        cerr << *it;
        if(it+1 != a.end()) {
            cerr << ", ";
        } else break;
    }
    cerr << " ]\n";
}
template<typename T> 
void print(const vector<array<T, 3>> a){ 
    cerr << "[ ";
    for(auto it = a.begin(); it!=a.end(); it++) {
        print(*it);
        if(it+1 != a.end()) {
            cerr << ", ";
        } else break;
    }
    cerr << " ]\n";
}
template<typename T, typename T0> 
void print(vector<pair<T,T0>> a){ 
    cerr << "[ "; 
    for(pair<T,T0> x: a) print(x); 
    cerr << " ]\n";
}

/* map */
template<typename T, typename T0> 
void print(map<T,T0> a){ 
    cerr << "[ "; 
    for(pair<T,T0> x: a) cerr << "{ " << x.ff << ": " << x.ss << "}, "; 
    cerr << " ]\n";
}

/* set */
template<typename T> 
void print(set<T> a){ 
    cerr << "[ "; 
    for(T x: a) cerr << x << ", "; 
    cerr << " ]\n";
}
#define debug(...) cerr << #__VA_ARGS__ << ": "; print(__VA_ARGS__);