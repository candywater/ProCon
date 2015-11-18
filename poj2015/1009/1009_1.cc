/*正式バージョン*/

#include <cstdio>
#include <iostream>
using namespace std;
int a[1001]={0};
int b[1001]={0};
int width;
int length=0;
int i1,i2;

//input index,output value where index is
int find(int index){
	//no error check ,cause it's troublesome....
	//i wrote an error 回避:w
	//cout <<"finded:"<<index<<endl;
	int i=0;
	while(index>0 ){
		index-=b[i];
		i++;
		if(i>=1001)
			return -1;
	}
  //i1はfindで探した該当点が配列における添字、i2は該当点がその配列の該当箱のなかにおける順番
	i1=i-1;
	i2=index+b[i1];
  //cout << "---arrayIndex:"<<i1<<" index:"<<i2<<" a[i]:"<<a[i1]<<" b[i]:"<<b[i1]<<endl;
	return a[i-1];
}

/*
	 u_l,u_u,u_r,
	 l_l,r_r,
	 d_l,d_d,d_r,
	 */
/*
	 index は１から始まり
	 lengthも１から始まる一個目は１、二個目は２

	 index%width = 1 ならば 第一列
	 index%width = 0 ならば 一番右の列

	 index-width <=0 ならば 第一行
	 index+width >=length ならば 一番下の行

	 ここでは、絶対値を返さずに、単にその点のpixel値を返すだけ
	 */
/*
	 大量データの改善策1
	 3行以上同じデータが続く場合、それを０とみなし、計算せずに代入する
	 改善策２
	 widthが大きすぎる場合でも改善策せねばということで、
	 やってみよ。
	 1000000000 0 1000000000 0 0 

*/


int u_l(int index){
	if(index%width==1 || index-width<=0)
		return -1;
	return find(index-width-1);
}
int u_u(int index){
	if(index-width<=0)
		return -1;
	return find(index-width);
}
int u_r(int index){
	if(index%width==0 || index-width<=0)
		return -1;
	return find(index-width+1);
}
int l_l(int index){
	if(index%width==1)
		return -1;
	return find(index-1);
}
int r_r(int index){
	if(index%width==0)
		return -1;
	return find(index+1);
}
int d_l(int index){
	if(index%width==1 || index+width>length)
		return -1;
	return find(index+width-1);
}
int d_d(int index){
	if(index+width>length)
		return -1;
	return find(index+width);
}
int d_r(int index){
	if(index%width==0 || index+width>length)
		return -1;
	return find(index+width+1);
}

//cout <<"find(index+width+1):"<<find(index+width+1)<<endl;
int main(void){
	while(true){
		int c[2002];
		int d[2002];
		cin >> width;
		if(width==0){
			cout << "0" << endl;
			return 0;
		}

		int i=0;
		//input
		for(;i<1001;i++){
			cin >> a[i] >> b[i];
			if(b[i]==0) break;
			//get the length
			length+=b[i];
		}
		//cout << a[j] << " " << b[j] << endl;
		//cout << "length:" << length << endl;
		int tmpc=-1,tmpd=0,tmp,pixel;//tmpdすなわちdでのcount
		//int sum=0,average,count=0;
		int maximum;
		int index=0;//indexは１から始まるすべての座標のインデックス
		int cdindex=0;//cdindexは配列の添字

		//一行しかない場合...なぜかこのコード間違っている
		if(i==1){
			if(b[0]==1){
				cout << width<< endl;
				cout <<a[0]<<" "<<b[0]<<endl;
				cout <<"0 0"<<endl;
			}
			else {
				cout << width << endl;
				cout << "0 " << b[0] << endl;
				cout << "0 0"<< endl;
			}
			//終われば初期化
			for(int j=0;j<1001;j++){
				if(b[j]==0) break;
				a[j]=0;b[j]=0;
			}
			length=0;
			continue;
		}

		//ここからはすべての座標について調べる:w
		while(true){
			maximum=0;
			index++;
			if(index>length)
				break;

			pixel=find(index);

			//３行以上連続同じ数字の続く
			if(b[i1]>=width*3){
				if(i2>width && i2<=b[i1]-width){
					//前までの最大値が0でなければ、それを記録する
					if(tmpc!=0 ){
						c[cdindex]=tmpc;
						d[cdindex++]=tmpd;
						tmpc=0;
						tmpd=b[i1]-width*2;
						index+=b[i1]-width*2-1;
					}
					//0ならば、3行以上連続する場合、一行と尾行を除けば
					//全部0なので、0を続いて記録
					else {
						tmpd+=b[i1]-width*2;
						index+=b[i1]-width*2-1;
					}
					continue;
				}
			}

			/*maximumをもとめる部分*/
			tmp=u_l(index);
			//cout << "maximum:"<<maximum<<" index:"<<index<<endl;
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp);//tmpの絶対値を取る:w
				if(maximum<tmp) maximum=tmp;
			//cout << "u_l_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=u_u(index);            
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "u_u_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=u_r(index); 
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "u_r_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=l_l(index);
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "l_l_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=r_r(index);
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "r_r_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=d_l(index);     
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "d_l_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=d_d(index);      
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "d_d_maximum:"<<maximum<<" index:"<<index<<endl;
			}
			tmp=d_r(index);       
			if(tmp!=-1){
				tmp=tmp-pixel;
				tmp=(tmp>0)?tmp:(-tmp); 
				if(maximum<tmp) maximum=tmp;
			//cout << "d_r_maximum:"<<maximum<<" index:"<<index<<endl;
			}

			//全データのはじめの一個目
			if(tmpc==-1){
				tmpc=maximum;
				tmpd=1;
			}
			//maxの数値が変わったら、
			else if(maximum!=tmpc){
        /*cout <<"***cdindex:"<<cdindex<<" tmpc:"<<tmpc
          <<" tmpd:"<<tmpd<<" max:"<<maximum<<endl;*/
        c[cdindex]=tmpc;
				d[cdindex++]=tmpd;
				tmpc=maximum;
				tmpd=1;
			}
			else{
				tmpd++;
			}
		}//while
		c[cdindex]=tmpc;
		d[cdindex++]=tmpd;

		c[cdindex]=0;
		d[cdindex++]=0;

		//output
		cout << width << endl;
		for(int j=0;j<2002;j++){
			cout << c[j] << " " << d[j] << endl;
			if(d[j]==0 && c[j]==0)
				break;
		}
		//終われば初期化
		for(int j=0;j<1001;j++){
			if(b[j]==0) break;
			a[j]=0;b[j]=0;
		}
		length=0;


	}//while
	cout << "0" << endl;
	return 0;
}
