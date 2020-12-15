using System.Collections;
using System.Collections.Generic;
using System;

public class Solution
{
  readonly int[] dx = new int[]{0, 1, 0, -1};
  readonly int[] dy = new int[]{1, 0, -1, 0};

// ↓-- debug --↓
  static void Show<T>(T list){
    foreach(var i in list){
      Console.Write($@"{i} ");
    }
    Console.WriteLine();
  }
  static void ShowMatrix<T>(T matrix){
    foreach(var i in matrix){
      foreach(var j in matrix){
        Console.Write($"{i} ");
      }
      Console.WriteLine();
    }
    Console.WriteLine();
  }
// ↑-- debug --↑

  static void Main()
  {
  }
}