using System;
class main{
  static void Main(){
    string a;
    int num;
    int[] list = new int[10];
    for(int i = 0; ; i++){
      a = Console.ReadLine();
      if(a == null) break;
      num = Convert.ToInt32(a);
      list[i] = num;
    }

    Array.Sort(list);
    for(int i = 0; i < 3; i++){
      Console.WriteLine(list[list.Length - i - 1]);
    }

  }
}
