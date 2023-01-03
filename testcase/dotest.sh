for i in `seq 1 40`
do
  python testcase.py > input.txt
  ans1=$(../arihon/5 < input.txt)
  ans2=$(../arihon/5ans < input.txt)
  if [ $ans1 != $ans2 ]; then
      echo "Wrong Answer"
      echo $ans1
      echo $ans2
      exit
  else
    echo "Same Answer"
  fi
done