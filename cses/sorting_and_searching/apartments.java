import java.io.*;
import java.util.*;

public class apartments {
    static Reader bf = new Reader();
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int testcases = 1;
        // testcases = bf.nextInt();
        for(int t=1; t<=testcases; t++) {
            // out.print("Case " + t + ": ");
            solve();
        }

        out.flush(); out.close();
    }

    public static void solve() throws IOException {
        int n = bf.nextInt(), m = bf.nextInt(), k = bf.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>(), b = new ArrayList<Integer>();
        for(int i=0; i<n; i++) a.add(bf.nextInt());
        for(int i=0; i<m; i++) b.add(bf.nextInt());
        TreeMap<Integer, Integer> freq = new TreeMap<Integer, Integer>();
        for(int ai : a) {
            if(freq.containsKey(ai)) freq.put(ai, freq.get(ai)+1);
            else freq.put(ai, 1);
        }
        Collections.sort(b);
        int ans = 0;
        for(int i=0; i<m; i++) {
            Integer key = freq.higherKey(b.get(i)-k-1);
            if(key == null) continue;
            if(key <= b.get(i)+k) {
                ans++;
                int keyfreq = freq.get(key);
                if(keyfreq == 1) freq.remove(key);
                else freq.put(key, keyfreq-1);
            }
        }
        out.println(ans);
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException {
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
 
        public long nextLong() throws IOException {
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
 
        public double nextDouble() throws IOException {
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
 
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    } 
}
