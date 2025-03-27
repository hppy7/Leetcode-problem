class Solution {
    public double average(int[] salary) {
      double sum=0;
      double max=salary[0];
      double min=salary[0];
      for(int i=0;i<salary.length;i++)  
      {
      if(salary[i]>max)
      {
        max=salary[i];
      }
    else if(salary[i]<min)
     { min=salary[i];
     }
       sum+=salary[i];
      }
      sum=sum-max-min;
      int n=salary.length;
      n=n-2;
      double average=sum/n;
      return average;
    }
}