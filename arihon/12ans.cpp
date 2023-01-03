#include <cstdio>
#include <algorithm>
#include <utility>
#include <tuple>

std::tuple<double, int, int> item[201]{};
std::tuple<double, int, int> *end(item), *p, *q;
std::pair<int, long long> bb[300]{};
std::pair<int, long long> sub[300]{};
std::pair<int, long long> *s(sub), *b(bb);

long long lower(0);
long long upper(0);
int ws(0), W;
inline void off(int &w, int &v)
{
  int w1, w2;
  long long v1, v2;
  std::pair<int, long long> *i(bb), *j(bb);
  s = sub;
  while (i != b && j != b)
  {
    if ((w1 = i->first) > ws)
    {
      i = b;
      break;
    }
    if ((w2 = j->first - w) > ws)
    {
      j = b;
      break;
    }
    v2 = j->second - v;
    v1 = i->second;
    if (w1 > w2 && v1 < v2)
    {
      ++i;
      continue;
    }
    if (w2 >= w1 && v2 <= v1)
    {
      ++j;
      continue;
    }
    if (w1 <= w2)
    {
      *s++ = *i++;
      continue;
    }
    *s++ = std::make_pair(w2, v2);
    ++j;
  }
  while (i != b && i->first <= ws)
    *s++ = *i++;
  while (j != b && (w2 = j->first - w) <= ws)
    *s++ = std::make_pair(w2, j++->second - v);
}
inline void on(int &w, int &v)
{
  int w1, w2;
  long long v1, v2;
  std::pair<int, long long> *i(bb), *j(bb);
  s = sub;
  while (i != b && j != b)
  {
    if ((w1 = i->first) > ws)
    {
      i = b;
      break;
    }
    if ((w2 = j->first + w) > ws)
    {
      j = b;
      break;
    }
    v2 = j->second + v;
    v1 = i->second;
    if (w1 > w2 && v1 < v2)
    {
      ++i;
      continue;
    }
    if (w2 >= w1 && v2 <= v1)
    {
      ++j;
      continue;
    }
    if (w1 <= w2)
    {
      *s++ = *i++;
      continue;
    }
    *s++ = std::make_pair(w2, v2);
    ++j;
  }
  while (i != b && i->first <= ws)
    *s++ = *i++;
  while (j != b && (w2 = j->first + w) <= ws)
    *s++ = std::make_pair(w2, j++->second + v);
}

inline void choice(double &d, double &e)
{
  long long y;
  b = bb;
  for (auto &x : sub)
  {
    if (&x == s)
      return;
    (y = (&x)->first) -= W;
    y *= y > 0 ? d : e;
    if ((y += (&x)->second) >= lower)
      *b++ = x;
    upper = y > upper ? y : upper;
  }
}
int main()
{
  if (!~scanf("%*d%d", &W))
    return 0;
  int v;
  int w;
  while (~scanf("%d%d", &v, &w))
  {
    if (w > W)
      continue;
    *end++ = std::make_tuple(-(double)v / w, w, v);
  }
  std::sort(item, end);

  for (auto &x : item)
  {
    std::tie(std::ignore, w, v) = x;
    if (!w)
      return !printf("%lld\n", lower);
    if (ws + w > W)
    {
      p = q = &x;
      break;
    }
    ws += w;
    lower += v;
  }

  *b++ = std::make_pair(ws, lower);
  ws += W;
  std::pair<int, long long> U(std::make_pair(W + 1, 1));
  double d, e;
  while (lower != upper && (p != item || q != end))
  {
    if (p != item)
    {
      std::tie(std::ignore, w, v) = *--p;
      ws -= w;
      off(w, v);
      auto it = std::begin(sub);
      it = std::lower_bound(it, it + (s - sub), U);
      lower = (it - 1)->second;
      d = (p != item ? std::get<double>(*(p - 1)) : 0);
      e = std::get<double>(*q);
      choice(d, e);
    }
    if (q != end)
    {
      std::tie(std::ignore, w, v) = *q;
      on(w, v);
      auto it = std::begin(sub);
      it = std::lower_bound(it, it + (s - sub), U);
      lower = (it - 1)->second;
      d = (p != item ? std::get<double>(*(p - 1)) : 0);
      e = std::get<double>(*++q);
      choice(d, e);
    }
  }
  return !printf("%lld\n", lower);
}