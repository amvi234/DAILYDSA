package java;
class Solution {
    public List<List<Integer>> generate(int numRows) {
         List<List<Integer>> list = new ArrayList<>();
        for(int i=1;i<=numRows;i++){
            List<Integer> list2 = new ArrayList<>();
            if(i==1){
                list2.add(i);
                list.add(list2);
            }
            else if(i==2){
                list2.add(1);
                list2.add(1);
                list.add(list2);
            }
            else{
                list2.add(1);
                List<Integer> l = new ArrayList<>(list.get(i-2));
                for(int j=0;j<l.size()-1;j++){
                    list2.add(l.get(j)+l.get(j+1));
                }
                list2.add(1);
                list.add(list2);
            }
        }
        return list;
    }
}