function y0 = newtone(x0, x, f)
  y0 = f(1);
  n = length(x);
  h = (x(end) - x(1)) / (n-1);
  delta = _delta(f);
  for k = 2: n
    p = 1;
    for j = 1 : k - 1
      p .*= (x0 - x(j));
    endfor
    y0 .+= (delta(k) * p) ./ (factorial(k - 1) * h ^ (k - 1));
  endfor
endfunction

function d = _delta(f)
  n = length(f);
  d(1) = f(1);
  for i = 2 : n
    f = diff(f);
    d(i) = f(1);
  endfor
endfunction