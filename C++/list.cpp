

void sort(vector<string>& v) {
  int sidx = 0;

  for(int i =0; i < v.size() - 1; ++i){
    sidx = i;
    for(int j=i+1; j < v.size(); ++j){
      if(v[j] < v[sidx])
        sidx = j;
    }
    string temp = v[i];
    v[i] = v[sidx]
    v[sidx] = temp;
  }
}

int binarySearch(const vector<string> & v, string target) {
  int first = 0;
  int last = v.size() - 1;
  int mid;

  while(first <= last) {
    mid = (first + last) / 2;
    if(target == v[mid])
      return mid;
    else if(target < v[mid])
      last = mid - 1;
    else
      first = mid +1;
  }
  return -1;
}
