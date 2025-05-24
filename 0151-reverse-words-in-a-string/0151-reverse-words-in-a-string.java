class Solution {
    public String reverseWords(String s) {
      String[] arr=s.split("\\s+"); // split on the basic of spaces; 
      StringBuilder sb=new StringBuilder("");
      for(int i=arr.length-1;i>=0;i--)
      {
      sb.append(arr[i]+" ");

      }
    String ans=sb.toString(); // convert sb string into ans
    ans=ans.trim();  // to remove the extra space from string  mean last space or extra space
   return ans;
    }
}