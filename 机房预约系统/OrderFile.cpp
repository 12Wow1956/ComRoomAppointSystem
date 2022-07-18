#include "OrderFile.h" 

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date, interval, stuId, stuName, roomId, status;

	this->m_size = 0;

	while (ifs >> date && ifs >> interval &&  ifs >> stuId && ifs >> stuName && ifs >> stuId && ifs >> roomId && ifs >> status) {
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/

		map<string, string> m;
		// date:1
		string key;
		string value;
		int pos = date.find(":"); // 4
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);   // 6 - pos - 1
		}
		//cout << "key = " << key << "value = " << value << endl;
		m.insert(make_pair(key, value));


		// 时间段
		pos = interval.find(":"); 
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, date.size() - pos - 1);   
		}
		m.insert(make_pair(key, value));


		// 学号
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, date.size() - pos - 1);
		}
		m.insert(make_pair(key, value));


		// 用户名
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, date.size() - pos - 1);
		}
		m.insert(make_pair(key, value));


		// 机房
		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, date.size() - pos - 1);
		}
		m.insert(make_pair(key, value));


		// 状态
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, date.size() - pos - 1);
		}
		m.insert(make_pair(key, value));

		this->m_orderDate.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	
	// test
	for (map<int, map<string, string>>::iterator it = this->m_orderDate.begin(); it != this->m_orderDate.end(); ++it) {
		cout << "记录数：" << it->first << " 预约记录：" << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); ++mit) {
			cout << " key =  "<< mit->first << " value = " << mit->second << " ";
		}
		cout << endl;
	}

	ifs.close();
}

// 更新预约记录
void OrderFile::updateOrder() {

}