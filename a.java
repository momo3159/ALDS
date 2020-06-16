package test;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

public class Test {

	public static void main(String[] args) {
		String urlS = "https://challenge-server.code-check.io/api/kidnapper/";
		String token ="52baaa19-5056-418b-ac6d-0a0372e6b740";
		URL url;

		try {
			URLConnection conn;
			InputStream in;
			BufferedReader br = null;

			String url_s = urlS + "start?token=" + token;
			url = new URL(url_s);
			conn = url.openConnection();
			in = conn.getInputStream();
			br = new BufferedReader(new InputStreamReader(in));
			String line;
			line = br.readLine();
			String[] info = new String[2];
			info = line.split(": ");

			while(true) {
				if(info[0].equals("changed_my_mind")) {
					return;
				}
				else {
					if(info[0].equals("put_the_bag")){
						System.out.println("to");
						return;
					}
					else {
						url_s = urlS + "deliver?token=" + token + "&to=" + info[1];
						url = new URL(url_s);
						conn = url.openConnection();
						in = conn.getInputStream();
						br = new BufferedReader(new InputStreamReader(in));
						line = br.readLine();
						info = line.split(": ");
					}
				}
			}
		}
		catch (MalformedURLException e) {
			e.printStackTrace();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}
