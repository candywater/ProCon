using System;

class main {
  static void Main(){
    string input;
    int[] lines = new int[3];
    input = Console.ReadLine();//読み飛ばす
    while((input = Console.ReadLine()) != null) {
      if(isTriangle( lines, input ))
        Console.WriteLine("YES");
      else
        Console.WriteLine("NO");
    }
  }
  private static bool isTriangle(int[] lines, string input){
    string[] strlines = input.Split(new char[] {' '});
    for(int i = 0; i < 3; i++)
      lines[i] = Convert.ToInt32(strlines[i]);
    Array.Sort(lines);
    //Console.WriteLine("{0} {1} {2}", lines[0], lines[1], lines[2]);
    return 
      lines[0]*lines[0] + lines[1]*lines[1] == lines[2] * lines[2];
  }
}