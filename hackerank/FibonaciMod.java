import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class FibonaciMod
{

	static BigInteger zero = new BigInteger("0");
	static BigInteger one = new BigInteger("1");
	static BigInteger two = new BigInteger("2");
	
	static BigInteger[] dp = new BigInteger[25];
	static BigInteger  solve(BigInteger a,BigInteger b,BigInteger n)
	{
		if(n.equals(zero))return a;
		if(n.equals(one))return b;
		BigInteger x = solve(a,b,n.subtract(one));
		return x.pow(2).add(solve(a,b,n.subtract(two)));
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String[] inp = sc.nextLine().split(" ");

		BigInteger l = solve(new BigInteger(inp[0]),new BigInteger(inp[1]),new BigInteger(inp[2]));

		System.out.println(l);
	}

}
