#ifndef reverse_inc
#define reverse_inc 1

namespace Blitz {

template <typename T>
struct reverse_range
{
private:
  T& x_;
 
public:
  reverse_range (T& x): x_ (x) {}
 
  auto begin () const -> decltype (this->x_.rbegin ())
  {
    return x_.rbegin ();
  }
 
  auto end () const -> decltype (this->x_.rend ())
  {
    return x_.rend ();
  }
};
 
template <typename T>
reverse_range<T> reverse_iterate (T& x)
{
  return reverse_range<T> (x);
}

}

#endif
