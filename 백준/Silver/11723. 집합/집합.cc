#include <cstdio>

// 4MB 메모리 제한: 입출력 버퍼 각 64KB (총 0.13MB 사용으로 매우 안전)
const int BSIZE = 1 << 16;
char buffer[BSIZE];
int idx = BSIZE;
int n_read = 0;

char wbuffer[BSIZE];
int widx = 0;

// [입력] 버퍼에서 한 글자 읽기
inline char read() {
    if (idx == BSIZE) {
        n_read = fread(buffer, 1, BSIZE, stdin);
        idx = 0;
        if (n_read == 0) return 0; // EOF
    }
    return buffer[idx++];
}

// [입력] 정수 파싱 (명령어 뒤 찌꺼기 문자 자동 스킵)
inline int readInt() {
    int sum = 0;
    char c = read();
    // 숫자가 나올 때까지 계속 읽어서 버림 (add의 'dd', 공백 등)
    while (c < '0' || c > '9') c = read();
    while (c >= '0' && c <= '9') {
        sum = sum * 10 + (c - '0');
        c = read();
    }
    return sum;
}

// [출력] 버퍼에 쓰기
inline void writeChar(char c) {
    if (widx == BSIZE) {
        fwrite(wbuffer, 1, BSIZE, stdout);
        widx = 0;
    }
    wbuffer[widx++] = c;
}

// [출력] 문자열 쓰기
inline void writeStr(const char* s) {
    while (*s) writeChar(*s++);
}

int main() {
    int m = readInt();
    int bset = 0; // 비트마스크

    while (m--) {
        char c = read();
        // 공백/개행 건너뛰고 명령어 첫 글자 찾기
        while (c <= 32) c = read();

        if (c == 'a') {
            char next = read(); // 두 번째 글자 확인
            if (next == 'l') { // all
                bset = 0xfffff; // {1~20} 채우기
                
                // [이전 코드의 버그 수정]
                // 'all' 뒤에 남은 문자('l')를 확실히 소비해서 버려야 함
                while (read() > 32); 
            } else { // add
                // 'add' 뒤의 'dd'는 readInt가 숫자를 찾으면서 알아서 버림
                int x = readInt();
                bset |= (1 << (x - 1));
            }
        }
        else if (c == 'r') { // remove
            int x = readInt();
            bset &= ~(1 << (x - 1));
        }
        else if (c == 'c') { // check
            int x = readInt();
            if ((bset >> (x - 1)) & 1) writeStr("1\n");
            else writeStr("0\n");
        }
        else if (c == 't') { // toggle
            int x = readInt();
            bset ^= (1 << (x - 1));
        }
        else if (c == 'e') { // empty
            bset = 0;
            // [이전 코드의 버그 수정]
            // 'empty' 뒤의 'mpty'를 확실히 소비해서 버려야 함
            while (read() > 32);
        }
    }

    // 출력 버퍼 비우기
    if (widx > 0) fwrite(wbuffer, 1, widx, stdout);

    return 0;
}