#include "node.h"

node::node(trainList* _datas)
{
    datas = _datas;
    decision = "not_over";
}

bool node::checkDecision(){
    if(!datas->data.size()){
        return true; // 如果训练集为空，决策结果唯一
    }
    string deci = datas->data.at(0).getPlayTennis();
    for(dataItem item : datas->data){
        if(deci != item.getPlayTennis()){
            return false;
        }
    }
    decision = deci;
    return true;
}

double node::compute_entropy(pair_di deci ){
    double sum = 0.00;
    int total = deci.first + deci.second;
    sum += deci.first / total * log2(deci.first / total);
    sum += deci.second / total * log2(deci.second / total);
    return -(sum);
}


pair_di node::get_decision(vector<dataItem> items){
    int play = 0;
    int notplay = 0;
    for (int i = 0; i < items.size(); i++)
    {
        if(items.at(i).getPlayTennis() == "play"){
            play += 1;
        }else{
            notplay += 1;
        }
    }
    return make_pair(play , notplay);
}

string node::find_max_info(){
    vector<double> infos;
    // 计算熵
    double entropy = compute_entropy(get_decision(datas->data));
    // 计算信息增益
    for(string attribute : datas->attributes){
        vector<double> condition_entropy;
        double info = compute_info(attribute );
        infos.push_back(info);
    }
    // 计算最大信息增益
    
}

void classify(classData cd){
    // 目的，将classData 按属性值作为key值，存到map中，如：{晴：[row1,row2] , ...}
    mapClass mc;
    for(classDataRow row : cd){
        mapClass::iterator f_lt = mc.find(row.first);
        if(f_lt != mc.end()){ // 如果字典中有当前属性
            classData &container = mc[row.first];
            container.push_back(row);
        }else{// 如果字典中没有当前属性
            classData newCD;
            newCD.push_back(row);
            mc.insert(pair<string , classData>(row.first , newCD));
        }
    }
}

double node::compute_info(string attribute ){
    classData attribute_rows = datas->map_attribute[attribute];
    // vector<string> attribute_array = datas->map_attribute[attribute];
    
}

double node::compute_condition_entropy(){

}
