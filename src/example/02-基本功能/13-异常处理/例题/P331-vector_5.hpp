#include <memory>
#include <utility>

template <typename T, typename A = std::allocator<T>>
struct VectorBase {
  VectorBase(const A& a, typename A::size_type n)
      : alloc{a}, elem{alloc.allocate(n)}, space{elem + n}, last{elem + n} {}
  VectorBase(const VectorBase&) = delete;  // 无拷贝操作
  VectorBase(VectorBase&&) noexcept;       // 移动操作

  auto operator=(const VectorBase&) -> VectorBase& = delete;
  auto operator=(VectorBase&&) noexcept -> VectorBase&;

  ~VectorBase() { alloc.deallocate(elem, last - elem); }

  A alloc;   // 分配器
  T* elem;   // 分配空间的开始
  T* space;  // 元素序列的末尾，可扩展空间的开始
  T* last;   // 已分配空间的末尾
};

template <typename T, typename A>
VectorBase<T, A>::VectorBase(VectorBase&& a) noexcept
    : alloc{a.alloc}, elem{a.elem}, space{a.space}, last{a.space} {
  a.elem = a.space = a.last = nullptr;  // 不再拥有任何内存
}

template <typename T, typename A>
auto VectorBase<T, A>::operator=(VectorBase&& a) noexcept -> VectorBase& {
  swap(*this, a);
  return *this;
}

template <typename T, typename A = std::allocator<T>>
class Vector {
 public:
  using size_type = unsigned int;

  explicit Vector(size_type n, const T& val = {}, const A& a = {});
  Vector(const Vector& a);      // 拷贝构造函数
  Vector(Vector&& a) noexcept;  // 移动构造函数

  auto operator=(const Vector& a) -> Vector&;      // 移动赋值运算
  auto operator=(Vector&& a) noexcept -> Vector&;  // 移动赋值运算

  ~Vector() { destroy_elements(); }

  [[nodiscard]] auto size() const -> size_type { return vb_.space - vb_.elem; }
  [[nodiscard]] auto capacity() const -> size_type {
    return vb_.last - vb_.elem;
  }

  void reserve(size_type);  // 增加存储容量

  void resize(size_type, const T& = {});  // 改变元素个数
  void clear() { resize(0); }             // 清空 vector
  void push_back(const T&);               // 在末尾添加一个元素
 private:
  void destroy_elements();

  VectorBase<T, A> vb_;  // 此处为数据
};

template <typename T, typename A>
Vector<T, A>::Vector(size_type n, const T& val, const A& a) : vb_{a, n} {
  std::uninitialized_fill(vb_.elem, vb_.elem + n, val);
}

template <typename T, typename A>
Vector<T, A>::Vector(const Vector& a) : vb_{a.vb_.alloc, a.size()} {
  std::uninitialized_copy(a.begin(), a.end(), vb_.elem);
}

template <typename T, typename A>
Vector<T, A>::Vector(Vector&& a) noexcept : vb_{std::move(a.vb_)} {
}

// note: P331 赋值操作：避免重复，提供强保障（见 13.2 节）
template <typename T, typename A>
auto Vector<T, A>::operator=(const Vector& a) -> Vector& {
  Vector temp{a};          // 拷贝分配器
  std::swap(*this, temp);  // 交换内容
  return *this;
}

template <typename T, typename A>
auto Vector<T, A>::operator=(Vector&& a) noexcept -> Vector& {
  clear();         // 销毁元素
  swap(*this, a);  // 转移所有权
}

template <typename T, typename A>
void Vector<T, A>::destroy_elements() {
  for (T* p{vb_.elem}; p != vb_.space; ++p) {
    p->~T();  // 销毁元素（见 17.2.4 节）
  }
  vb_.space = vb_.elem;
}