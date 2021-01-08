#include <iostream>
#include <unordered_map>

using namespace std; 

class SparseVector {
public: 
  SparseVector(unordered_map<size_t, double> mapIdxVal) : _mapIdxVal(mapIdxVal) { }
    
  ~SparseVector() = default; 
  
  double innerProduct(const SparseVector& sparseVectorIn) const {    
      // calcualte the inner product between two sparse vectors
      double sum; 
      for(auto& ele : _mapIdxVal) {        
        /**
         * traverse the non-trivial values in the hash map, and multiple with the
         * corresponding value in the input sparse vector
         **/
        sum += ele.second * sparseVectorIn.getVal(ele.first);
      }      
      return sum; 
  }
  
  double getVal(size_t key) const {
    /**
     * return the value if the key can be found in the map, i.e. the index 
     * points to a non-trivial value; otherwise, return 0.0
     **/ 
    return _mapIdxVal.find(key) != _mapIdxVal.end() ? 
           _mapIdxVal.at(key) : 0.0; 
  }
  
private: 
  /**
   * an unordered map is used to store the values in the parse vector
   * - key: the index of a non-trivial value in a sparse vector
   * - value: a non-trival value
   **/
  unordered_map<size_t, double> _mapIdxVal; 
  
};

int main() {  
  
  SparseVector sparseVector1(unordered_map<size_t, double> {make_pair(0, 1.0), make_pair(1, 1.0), make_pair(4, 3.0)}); 
  SparseVector sparseVector2(unordered_map<size_t, double> {make_pair(0, 1.0), make_pair(4, 3.0)}); 
  
  // the expected value is 10
  double innerProduct = sparseVector1.innerProduct(sparseVector2); 
  
  cout << "inner product = " << innerProduct << endl;   
  
  return EXIT_SUCCESS; 

}