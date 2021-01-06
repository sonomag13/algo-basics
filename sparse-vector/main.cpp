#include <iostream>
#include <unordered_map>

using namespace std;

class SparseVector {
public: 
  SparseVector(unordered_map<int, double> mapIdxVal) : _mapIdxVal(mapIdxVal) { }
    
  ~SparseVector() = default; 
  
  double innerProduct(const SparseVector& vector2) const {    
      double sum;     
      for(auto& ele : _mapIdxVal) {        
        sum += ele.second * vector2.getVal(ele.first);         
      }      
      return sum; 
  }
  
  double getVal(int key) const {
    if (_mapIdxVal.find(key) != _mapIdxVal.end()) {
      return _mapIdxVal.at(key); 
    }
    else {
      return 0.0; 
    }    
  }
  
private: 
  unordered_map<int, double> _mapIdxVal; 
  
};


// To execute C++, please define "int main()"
int main() {
  
  unordered_map<int, double> map1{make_pair(0, 1.0), make_pair(1, 1.0), make_pair(4, 3)}; 
  unordered_map<int, double> map2{make_pair(0, 1.0), make_pair(4, 3)}; 
  
  SparseVector vector1(map1); 
  SparseVector vector2(map2); 
  
  double innerProduct = vector1.innerProduct(vector2); 
  
  cout << "inner product = " << innerProduct << endl;   
  
  return 0; 
}

