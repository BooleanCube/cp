import java.io.*;
import java.util.*;

public class treediameter {
    public static void main(String[] args) throws IOException {
        Reader bf = new Reader();
        int n = bf.nextInt();
        node[] nodes = new node[n+1];
        for(int i=1; i<=n; i++) nodes[i] = new node();
        for(int i=0; i<n-1; i++) {
            int s = bf.nextInt();
            int e = bf.nextInt();
            nodes[s].adj.add(e);
            nodes[e].adj.add(s);
        }
        ArrayDeque<Integer> q = new ArrayDeque<>();
        HashSet<Integer> v = new HashSet<>();
        int end = -1;
        q.addLast(1);
        while(!q.isEmpty()) {
            int current = q.removeFirst();
            v.add(current);
            for(int node : nodes[current].adj) {
                if(v.contains(node)) continue;
                q.addLast(node);
            }
            if(q.isEmpty()) end = current;
        }
        q = new ArrayDeque<>();
        v = new HashSet<>();
        int[] dist = new int[n+1];
        q.addLast(end);
        dist[end] = 0;
        while(!q.isEmpty()) {
            int current = q.removeFirst();
            v.add(current);
            for(int node : nodes[current].adj) {
                if(v.contains(node)) continue;
                q.addLast(node);
                dist[node] = dist[current] + 1;
            }
            if(q.isEmpty()) end = current;
        }
        System.out.println(dist[end]);
    }
}

class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(
            new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') {
                if (cnt != 0) {
                    break;
                }
                else {
                    continue;
                }
            }
            buf[cnt++] = (byte)c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0,
                             BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
    }
}

class node {
    public ArrayList<Integer> adj = new ArrayList<>();
    public node() {}
}
