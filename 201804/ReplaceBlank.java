
public class ReplaceBlank {

	public static  void Replace(char string[]){
		if (string == null) {
      return;
    }
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(i<string.length){
      originalLength++;
      if (string[i] == ' ') {
        numberOfBlank++;
      }
      i++;
    }
    int newLength = originalLength+numberOfBlank*2;
    char[] newString = new char[newLength];
    System.out.println("string.length:"+string.length+",newLength:"+newLength);

    int indexOfNew = newLength-1;
    int indexOfOriginal = originalLength-1;
    while(indexOfOriginal >=0 && indexOfNew >= indexOfOriginal){
      if (string[indexOfOriginal] == ' ') {
        newString[indexOfNew --] = '#';
        newString[indexOfNew --] = '#';
        newString[indexOfNew --] = '#';
      }else {
        newString[indexOfNew --] = string[indexOfOriginal];
      }
      indexOfOriginal--;
    }
    System.out.print("newString:");
    System.out.println(newString);
	}

	public static void main(String args[]){
		System.out.println("hello world,java");
    String str="ab c d e ";
    System.out.println("str :"+str);
    char[] c=new char[str.length()];
    c=str.toCharArray();
    Replace(c);
  }
}
