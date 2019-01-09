public class FindinpartiallySortedMatrix {

	public static  boolean Find(int[] matrix, int rows, int columns, int number){
		boolean found = false;
		if (matrix != null && rows > 0 && columns > 0) {
			int row = 0;
			int column = columns - 1;
			while (row < rows && column >= 0){
				if (matrix[row * columns + column] == number) {
					found = true;
					System.out.println("location at row: "+row +",column: "+column);
					break;
				}
				else if (matrix[row * columns + column] > number) {
					column--;
				}else {
					row ++;
				}
			}
		}
		return found;
	}

	public static void main(String args[]){
		System.out.println("hello world,java");
		int a[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
		int number = 4;
		if (Find(a,4,4,number)) {
			System.out.println("found number "+number);
		}else {
			System.out.println("number "+number+"no in list" + a);
		}
	}
}
