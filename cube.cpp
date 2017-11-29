#include<iostream>;
using namespace std;

const int MaxLength = 7;
const int SmallCubeMaxLength = MaxLength-1;

class SmallCube {
private:
    int length;
    int xcc, ycc, zcc;
    int Numbers[SmallCubeMaxLength][SmallCubeMaxLength][SmallCubeMaxLength];
public:
    //SmallCube();
    void setLength(const int i) { length = i; };
    int getLength() { return length; };
    //int getNumber(const int x, y, z) {}
    void setNumber(const int x, const int y, const int z, const int X) { Numbers[x][y][z] = X; };
    int getNumber(const int x, const int y, const int z) { return Numbers[x][y][z];};
    int getx() { return xcc; };
    int gety() { return ycc; };
    int getz() { return zcc; };
    void setPosition(const int x, const int y, const int z) { xcc = x; ycc = y; zcc = z; };

    int getTotal() {
        int sum(0);
        for (int x = 0; x < length; x++) {
            for (int y = 0; y < length; y++) {
                for (int z = 0; z < length; z++) {
                    sum += Numbers[x][y][z];
                }
            }
        }
        return sum;
    }
};

class BigCube {
private:
    int length;
    int Numbers[MaxLength][MaxLength][MaxLength];
public:
    BigCube(int l) { length = l;};
    int getLength() { return length; };
    //void setLength(int i) { length = i; };
    int getNumber(const int x, const int y, const int z) { return Numbers[x][y][z]; };
    int setNumber(const int x, const int y, const int z, const int X) { Numbers[x][y][z] = X; };
};

void PlaceCube (SmallCube &SmallCube, BigCube &BigCube, const int P){
    const int M = BigCube.getLength();
    const int n = SmallCube.getLength();
    const int put = M-n+1; //slots = cube(M-n+1);
    const int SmallCubeSum = SmallCube.getTotal();
    //cout << "put " << put << endl;
    for (int x = 0; x < put; x++) {
        for (int y = 0; y < put; y++) {
            for (int z = 0; z < put; z++) {

                //find the sum of the cells involved in BigCube
                int BigCubeSum(0);
                for (int xx = x; xx < (x+n); xx++){
                    for (int yy = y; yy < (y+n); yy++){
                        for (int zz = z; zz < (z+n); zz++) {
                            BigCubeSum += BigCube.getNumber(xx, yy, zz);
                        }
                    }
                }
            if ((BigCubeSum+SmallCubeSum) % P == 0) { //if bigcube sum > 0?
                //cout << "x" << x << " y" << y << " z" << z << endl;
                SmallCube.setPosition(x, y, z);
                //clear the cubes
                for (int xx = x; xx < (x+n); xx++){
                    for (int yy = y; yy < (y+n); yy++){
                        for (int zz = z; zz < (z+n); zz++) {
                            BigCube.setNumber(xx, yy, zz, 0);
                        }
                    }
                }
                return;
            }
            }
        }
    }
}

main(){
    //input big cube
    int M, N, P;
    cin >> M >> N >> P;
    BigCube BigCube(M);
    // input increase z first, then y, then x
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < M; y++) {
            for (int z = 0; z < M; z++) {
                int X;
                cin >> X;
                BigCube.setNumber(x, y, z, X);
            }
        }
    }
    SmallCube cubes[N];
    for (int n = 0; n < N; n++) {
        int l;
        cin >> l;
        cubes[n].setLength(l);
        for (int x = 0; x < l; x++) {
            for (int y = 0; y < l; y++) {
                for (int z = 0; z < l; z++) {
                        int bigNumber = BigCube.getNumber(x, y, z);
                    int X;
                    cin >> X;
                    cubes[n].setNumber(x, y, z, X);
                }
            }
        }
    }

    //SortCubes
    //biggest cube is in 0, smallest cube is in N
    SmallCube SortedCubes[N];
    int n = 0;
    int order[N];
    for (int i = SmallCubeMaxLength; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            if (cubes[j].getLength() == i) {
                SortedCubes[n].setLength(i);
                order[n] = j; //record for ordered output
                //cout << "n" << n << endl;
                for (int x = 0; x < i; x++) {
                    for (int y = 0; y < i; y++) {
                        for (int z = 0; z < i; z++) {
                            int X = cubes[j].getNumber(x, y, z);
                            //cout << "X = " << X << "; n = " << n << endl;
                            SortedCubes[n].setNumber(x, y, z, X);
                        }
                    }
                }
                n++;
            }
        }
    }
    //insert from biggest cube
    for (int i = 0; i < N; i++) {
        PlaceCube(SortedCubes[i], BigCube, P);
    }

    //output the cubes in original order
    for (int n = 0; n < N; n++) {
        int OriginalOrder = order[n];
        //cout << "origin" << OriginalOrder << endl;
        cout << SortedCubes[OriginalOrder].getx() << " " << SortedCubes[OriginalOrder].gety() << " " << SortedCubes[OriginalOrder].getz() << endl;
    }
    return 0;
}
