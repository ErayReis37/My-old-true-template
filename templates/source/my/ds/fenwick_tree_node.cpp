
struct fn {
  @@HERE@@
  fn operator+(fn ot) {
    fn res;
    ..
    return res;
  }
  fn operator-(fn ot) {
    fn res;
    ..
    return res;
  }
  fn operator+=(fn ot) {
    return *this = *this + ot;
  }
  fn operator-=(fn ot) {
    return *this = *this - ot;
  }
};
