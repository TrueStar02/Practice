double max(double p, double w, double s){
	if(p>=w&&p>=s) return p;
	else if(w>=p&&w>=s) return w;
	else return s;
}
void sort(struct Bread breads[], int size){
	int i, j, k;
	double key[10], temp;
	struct Bread tempb;
	for(i=0;i<10;i++){
		key[i]=breads[i].price+breads[i].weight+breads[i].size-max(breads[i].price, breads[i].weight, breads[i].size);
	    
	}
	for(i=0;i<10;i++){
		k=i;
		for(j=i+1;j<10;j++){
			if(key[j]>key[k]){
				k=j;
			}
		}
		if(k!=i){
			temp=key[k];
			key[k]=key[i];
			key[i]=temp;
			tempb=breads[k];
			breads[k]=breads[i];
			breads[i]=tempb;
		}
	}
    
}