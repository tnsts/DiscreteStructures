bool isSimple(int a){
  for(int i = 2; i < a; i++){
    if(!(a % i)){
      return 0;
    }
  }
  return 1;
}

int number_sum(int a){
  if(a < 0) a = -a;
  return (a/10 + a%10);
}
