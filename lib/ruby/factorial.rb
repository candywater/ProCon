# https://stackoverflow.com/questions/2434503/ruby-factorial-function/37352690#37352690
def factorial(m)
  i = 1;
  res = 1;
  (m-1).times do (i+=1; res*=i;) end;
  return res;
end