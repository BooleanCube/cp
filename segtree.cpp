vector<int> seg(2*n);

void upd(int idx, int val) {
    seg[idx] = val; idx >>= 1;
    while(idx) {
        seg[idx] = max(seg[idx*2], seg[idx*2+1]);
        idx >>= 1;
    }
}

int query(int l, int r, int t) {
    if(l == r) return seg[l] + t;
    if(l & 1) return query(l+1, r, t+seg[l]);
    if(r % 2 == 0) return query(l, r-1, t+seg[r]);
    return query(l>>1, r>>1, t);
}