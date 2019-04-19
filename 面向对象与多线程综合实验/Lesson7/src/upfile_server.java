import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

/**
 * @author: Yan_Daojiang
 * @date: 2018/12/19
 * @description:
 **/
public class upfile_server {
    public static void main(String[] args)throws  Exception{
        System.out.println("服务开启等待连接");
        ServerSocket serverSocket=new ServerSocket(10001);//建立serversocket对象，进行的通信的端口号为100001
        //使用循环不停的接收客户端发送的请求
        while(true){
            Socket s=serverSocket.accept();
            if(s!=null){
                System.out.println("收到服务器的请求,准备开始文件的上传");
            }
            //每次和客户端进行连接之后就单独开启一个线程进行与客户端的交互
            new Thread(new ServerThread(s)).start();

        }
    }
}



class ServerThread implements Runnable {
    private Socket socket;

    public ServerThread(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        String ip = socket.getInetAddress().getHostAddress();//获取客户端的IP
        System.out.println(ip);

        Random C=new Random();

        try {
            InputStream in = socket.getInputStream();
            File parentFile = new File("D:\\Java_Project\\Lesson6\\File\\uploadfile\\");
            if (!parentFile.exists())
                parentFile.mkdir();
            File file = new File(parentFile,    C.nextInt(20)+".txt");
            while (file.exists()) {
                file = new File(parentFile, ip + ".txt");
            }
            FileOutputStream fos = new FileOutputStream(file);
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = in.read(buf)) != -1) {
                fos.write(buf, 0, len);
            }

            OutputStream out = socket.getOutputStream();
            out.write("文件上传成功".getBytes());
            fos.close();
            socket.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
