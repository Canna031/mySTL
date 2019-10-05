/*
<<<<<<< HEAD
 *vector实现：
 *
 *这里缺省使用内部空间配置器alloc（详见1stl_alloctor.h），使用者也可以自行传入空间配置器
=======
<<<<<<< HEAD
 *vector实现：
 *
 *这里缺省使用内部空间配置器alloc（详见1stl_alloctor.h），使用者也可以自行传入空间配置器
=======
 *vector瀹炵幇锛�
 *
 *杩欓噷缂虹渷浣跨敤鍐呴儴绌洪棿閰嶇疆鍣╝lloc锛堣瑙�1stl_alloctor.h锛夛紝浣跨敤鑰呬篃鍙互鑷浼犲叆绌洪棿閰嶇疆鍣�
>>>>>>> update
>>>>>>> update
 */

#ifndef _STL_VECTOR_H_
#define _STL_VECTOR_H_

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
#include "1stl_alloctor.h"		//空间配置器
#include "1stl_construct.h"		//对象构造与析构
#include "1stl_iterator.h"		//for function distance
#include "1stl_uninitialized.h"	//for function uninitialized_*
#include "2stl_algobase.h"		//for diatance
#include <initializer_list>		//for 列表初始化
<<<<<<< HEAD
=======
=======
#include "1stl_alloctor.h"		//绌洪棿閰嶇疆鍣�
#include "1stl_construct.h"		//瀵硅薄鏋勯�犱笌鏋愭瀯
#include "1stl_iterator.h"		//for function distance
#include "1stl_uninitialized.h"	//for function uninitialized_*
#include "2stl_algobase.h"		//for
#include <initializer_list>		//for 鍒楄〃鍒濆鍖�
>>>>>>> update
>>>>>>> update
#include <cstddef>				//for ptrdiff_t

namespace lfp {

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
	//省缺使用第二级空间配置器
	template<class T, class Alloc = alloc>
	class vector {
	public:
		//vector的嵌套型别定义
		/* 因为vector是是在连续空间内存放，所以原生指针就可作为其迭代器 */
<<<<<<< HEAD
=======
=======
	//鐪佺己浣跨敤绗簩绾х┖闂撮厤缃櫒
	template<class T, class Alloc = alloc>
	class vector {
	public:
		//vector鐨勫祵濂楀瀷鍒畾涔�
		/* 鍥犱负vector鏄槸鍦ㄨ繛缁┖闂村唴瀛樻斁锛屾墍浠ュ師鐢熸寚閽堝氨鍙綔涓哄叾杩唬鍣� */
>>>>>>> update
>>>>>>> update
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type*		iterator;
		typedef value_type&		reference;
		typedef size_t			size_type;
		typedef ptrdiff_t		difference_type;

	private:
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
		//专属的空间配置器，配置时不是以字节为单位，而是以元素个数为单位
		typedef simple_alloc<value_type, Alloc> data_allocator;
		iterator start;				//目前使用空间的头
		iterator finish;			//目前使用空间的尾
		iterator end_of_storage;	//目前可用空间的尾

		//内部函数，调用构造器释放vector占用的所有空间
<<<<<<< HEAD
=======
=======
		//涓撳睘鐨勭┖闂撮厤缃櫒锛岄厤缃椂涓嶆槸浠ュ瓧鑺備负鍗曚綅锛岃�屾槸浠ュ厓绱犱釜鏁颁负鍗曚綅
		typedef simple_alloc<value_type, Alloc> data_allocator;
		iterator start;				//鐩墠浣跨敤绌洪棿鐨勫ご
		iterator finish;			//鐩墠浣跨敤绌洪棿鐨勫熬
		iterator end_of_storage;	//鐩墠鍙敤绌洪棿鐨勫熬

		//鍐呴儴鍑芥暟锛岃皟鐢ㄦ瀯閫犲櫒閲婃斁vector鍗犵敤鐨勬墍鏈夌┖闂�
>>>>>>> update
>>>>>>> update
		void deallocate() {
			if (start) {
				data_allocator::deallocate(start, end_of_storage - start);
			}
		}

<<<<<<< HEAD
		//配置n个元素的空间并填充内容
=======
<<<<<<< HEAD
		//配置n个元素的空间并填充内容
=======
		//閰嶇疆n涓厓绱犵殑绌洪棿骞跺～鍏呭唴瀹�
>>>>>>> update
>>>>>>> update
		void fill_initialize(size_type n, const T& value) {
			start = allocate_and_fill(n, value);
			finish = start + n;
			end_of_storage = finish;
		}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
		//内调函数，在pos处插入n个元素x，若空间不足进行扩容
		void insert_aux(iterator pos, size_type n, const T& x);

	public:		//vector的6种初始化方式
		vector() : start(0), finish(0), end_of_storage(0) { }	//1 默认构造
		explicit vector(size_type n) { fill_initialize(n, T()); }	//2 指定大小
		vector(int n, const T& value) { fill_initialize(n, value); }	//3	创建n个value
		vector(size_type n, const T& value) { fill_initialize(n, value); }
		template<class Iterator>
		vector(Iterator first, Iterator last) {		//4 用区间[first, last)初始化
<<<<<<< HEAD
=======
=======
		//鍐呰皟鍑芥暟锛屽湪pos澶勬彃鍏涓厓绱爔锛岃嫢绌洪棿涓嶈冻杩涜鎵╁
		void insert_aux(iterator pos, size_type n, const T& x);

	public:		//vector鐨�6绉嶅垵濮嬪寲鏂瑰紡
		vector() : start(0), finish(0), end_of_storage(0) { }	//1 榛樿鏋勯��
		explicit vector(size_type n) { fill_initialize(n, T()); }	//2 鎸囧畾澶у皬
		vector(int n, const T& value) { fill_initialize(n, value); }	//3	鍒涘缓n涓獀alue
		vector(size_type n, const T& value) { fill_initialize(n, value); }
		template<class Iterator>
		vector(Iterator first, Iterator last) {		//4 鐢ㄥ尯闂碵first, last)鍒濆鍖�
>>>>>>> update
>>>>>>> update
			size_type n = distance(first, last);
			start = data_allocator::allocate(n);
			uninitialized_copy(first, last, start);
			finish = start + n;
			end_of_storage = finish;
		}
<<<<<<< HEAD
		vector(const vector<T>& rhs) {		//5 拷贝构造
=======
<<<<<<< HEAD
		vector(const vector<T>& rhs) {		//5 拷贝构造
=======
		vector(const vector<T>& rhs) {		//5 鎷疯礉鏋勯��
>>>>>>> update
>>>>>>> update
			start = data_allocator::allocate(rhs.size());
			uninitialized_copy(rhs.start, rhs.finish, start);
			finish = start + rhs.size();
			end_of_storage = finish;
		}
<<<<<<< HEAD
		vector(std::initializer_list<T> init_list) {		//6 列表初始化
=======
<<<<<<< HEAD
		vector(std::initializer_list<T> init_list) {		//6 列表初始化
=======
		vector(std::initializer_list<T> init_list) {		//6 鍒楄〃鍒濆鍖�
>>>>>>> update
>>>>>>> update
			start = data_allocator::allocate(init_list.size());
			uninitialized_copy(init_list.begin(), init_list.end(), start);
			finish = start + init_list.size();
			end_of_storage = finish;
		}
		~vector() {
			if (start)
<<<<<<< HEAD
				destroy(start, finish);		//将对象析构
			deallocate();			//释放内存
=======
<<<<<<< HEAD
				destroy(start, finish);		//将对象析构
			deallocate();			//释放内存
=======
				destroy(start, finish);		//灏嗗璞℃瀽鏋�
			deallocate();			//閲婃斁鍐呭瓨
>>>>>>> update
>>>>>>> update
		}

		iterator begin() { return start; }
		iterator end() { return finish; }
		size_type size() const { return finish - start; }
		size_type capacity() const { return end_of_storage - start; }
		reference operator[](size_type n) { return *(start + n); }
		reference front() { return *begin(); }
		reference back() { return *(end() - 1); }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
		/* 在pos位置插入n个元素x */
		void insert(iterator pos, size_type n, const T& x) {
			insert_aux(pos, n, x);
		}
		/* 在pos位置插入一个元素x */
<<<<<<< HEAD
=======
=======
		/* 鍦╬os浣嶇疆鎻掑叆n涓厓绱爔 */
		void insert(iterator pos, size_type n, const T& x) {
			insert_aux(pos, n, x);
		}
		/* 鍦╬os浣嶇疆鎻掑叆涓�涓厓绱爔 */
>>>>>>> update
>>>>>>> update
		void insert(iterator pos, const T& x) {
			insert_aux(pos, 1, x);
		}

		void push_front(const T& x) {
			insert_aux(begin(), 1, x);
		}

		void push_back(const T& x) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
			if (finish != end_of_storage) {	  //如果未填满则直接在末尾构造元素
				construct(finish, x);
				++finish;
			}
			else {		//否则需要扩容
<<<<<<< HEAD
=======
=======
			if (finish != end_of_storage) {	  //濡傛灉鏈～婊″垯鐩存帴鍦ㄦ湯灏炬瀯閫犲厓绱�
				construct(finish, x);
				++finish;
			}
			else {		//鍚﹀垯闇�瑕佹墿瀹�
>>>>>>> update
>>>>>>> update
				insert_aux(end(), 1, x);
			}
		}

		void pop_front() {
			erase(begin());
		}

		void pop_back() {
			--finish;
			destroy(finish);
		}

		iterator erase(iterator pos) {		
<<<<<<< HEAD
			if (pos + 1 != end()) {		//如果不是删除最后一个元素，需要将后续元素向前移动
=======
<<<<<<< HEAD
			if (pos + 1 != end()) {		//如果不是删除最后一个元素，需要将后续元素向前移动
=======
			if (pos + 1 != end()) {		//濡傛灉涓嶆槸鍒犻櫎鏈�鍚庝竴涓厓绱狅紝闇�瑕佸皢鍚庣画鍏冪礌鍚戝墠绉诲姩
>>>>>>> update
>>>>>>> update
				copy(pos + 1, finish, pos);
			}
			--finish;
			destroy(finish);
			return pos;
		}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
		//删除[first, last)中所有元素
		iterator erase(iterator first, iterator last) {
			//将[last, finish)的内容移动到从first开始位置，返回最后复制的下一位置
			iterator it = copy(last, finish, first);

			/* 销毁[it, finish) 内的所有内容 */
			destroy(it, finish);
			finish = it;		//更新 finish 指向新的结尾
<<<<<<< HEAD
=======
=======
		//鍒犻櫎[first, last)涓墍鏈夊厓绱�
		iterator erase(iterator first, iterator last) {
			//灏哰last, finish)鐨勫唴瀹圭Щ鍔ㄥ埌浠巉irst寮�濮嬩綅缃紝杩斿洖鏈�鍚庡鍒剁殑涓嬩竴浣嶇疆
			iterator it = copy(last, finish, first);

			/* 閿�姣乕it, finish) 鍐呯殑鎵�鏈夊唴瀹� */
			destroy(it, finish);
			finish = it;		//鏇存柊 finish 鎸囧悜鏂扮殑缁撳熬
>>>>>>> update
>>>>>>> update
			return first;
		}

		void resize(size_type new_sz, const T& x) {
			if (new_sz < size()) {
				erase(begin() + new_sz, end());
			}
			else {
				insert_aux(end(), new_sz - size(), x);
			}
		}

		void resize(size_type new_sz) {
			resize(new_sz, T());
		}

		void swap(vector<T>& rhs) {
			swap(start, rhs.start);
			swap(end, rhs.end);
			swap(end_of_storage, rhs.end_of_storage);
		}

		void clear() {
			erase(begin(), end());
		}

	protected:
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
		//配置n个元素空间，并将其填充为value
		iterator allocate_and_fill(size_type n, const T& value) {
			iterator result = data_allocator::allocate(n);		//申请n个元素的空间
			uninitialized_fill_n(result, n, value);		//填充元素
<<<<<<< HEAD
=======
=======
		//閰嶇疆n涓厓绱犵┖闂达紝骞跺皢鍏跺～鍏呬负value
		iterator allocate_and_fill(size_type n, const T& value) {
			iterator result = data_allocator::allocate(n);		//鐢宠n涓厓绱犵殑绌洪棿
			uninitialized_fill_n(result, n, value);		//濉厖鍏冪礌
>>>>>>> update
>>>>>>> update
			return result;
		}
	};	//end of class vector



<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
	/* 内调函数，在pos处插入元素 x，若空间不足进行扩容 */
	//template<class T, class Alloc>
	//void vector<T, Alloc>::insert_aux(iterator pos, const T& x) {
	//	if (finish != end_of_storage) {		//还有备用空间
	//		//在备用空间起始(finish)处构造一个元素，并以vector最后一个元素(finish - 1)为初始值
	//		construct(finish, *(finish - 1));
	//		++finish;		//调整水位
	//		T x_copy = x;

	//		//将 [pos, finish - 2) 内的元素向后移动一格
	//		copy_backward(pos, finish - 2, finish - 1);		//交由高阶STL算法处理，实现见 2stl_algobase.h
	//		*pos = x_copy;		//在 pos 处插入新元素
	//	}
	//	else {		//没有备用空间
	//		const size_type old_capacity = size();
	//		const size_type new_capacity = (old_capacity == 0) ? 8 : 2 * old_capacity;
	//		/* 以上为内存空间配置原则: 如果原大小为0，则配置8，否则配置原空间大小的 2 倍 */
	//		/* 前半段用来放置原数据，后半段用来放置新数据 */
<<<<<<< HEAD
=======
=======
	/* 鍐呰皟鍑芥暟锛屽湪pos澶勬彃鍏ュ厓绱� x锛岃嫢绌洪棿涓嶈冻杩涜鎵╁ */
	//template<class T, class Alloc>
	//void vector<T, Alloc>::insert_aux(iterator pos, const T& x) {
	//	if (finish != end_of_storage) {		//杩樻湁澶囩敤绌洪棿
	//		//鍦ㄥ鐢ㄧ┖闂磋捣濮�(finish)澶勬瀯閫犱竴涓厓绱狅紝骞朵互vector鏈�鍚庝竴涓厓绱�(finish - 1)涓哄垵濮嬪��
	//		construct(finish, *(finish - 1));
	//		++finish;		//璋冩暣姘翠綅
	//		T x_copy = x;

	//		//灏� [pos, finish - 2) 鍐呯殑鍏冪礌鍚戝悗绉诲姩涓�鏍�
	//		copy_backward(pos, finish - 2, finish - 1);		//浜ょ敱楂橀樁STL绠楁硶澶勭悊锛屽疄鐜拌 2stl_algobase.h
	//		*pos = x_copy;		//鍦� pos 澶勬彃鍏ユ柊鍏冪礌
	//	}
	//	else {		//娌℃湁澶囩敤绌洪棿
	//		const size_type old_capacity = size();
	//		const size_type new_capacity = (old_capacity == 0) ? 8 : 2 * old_capacity;
	//		/* 浠ヤ笂涓哄唴瀛樼┖闂撮厤缃師鍒�: 濡傛灉鍘熷ぇ灏忎负0锛屽垯閰嶇疆8锛屽惁鍒欓厤缃師绌洪棿澶у皬鐨� 2 鍊� */
	//		/* 鍓嶅崐娈电敤鏉ユ斁缃師鏁版嵁锛屽悗鍗婃鐢ㄦ潵鏀剧疆鏂版暟鎹� */
>>>>>>> update
>>>>>>> update

	//		iterator new_start = data_allocator::allocate(new_capacity);
	//		iterator new_finish = new_start;
	//		try {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
	//			/* 先将原vector中 [start, pos) 的内容拷贝到 new_start 开始的位置 */
	//			new_finish = uninitialized_copy(start, pos, new_start);
	//			
	//			/* 在 new_finish(即pos) 处构造插入的元素 x */
	//			construct(new_finish, x);
	//			++new_finish;		//调整水位

	//			/* 再将原vector中 [pos, finish) 的内容拷贝到 new_finish 开始的位置 */
	//			new_finish = uninitialized_copy(pos, finish, new_finish);

	//			//元素插入完成，新 vector 构造完成
	//		} catch (...) {
	//			//捕获到异常，执行相应的销毁工作。注意：因为uninitialized_copy遵循commit or rollback
	//			//原则，所以构造失败时不需要自己执行对象销毁工作，只需要释放申请的内存就好
	//			data_allocator::deallocate(new_start, new_capacity);		//释放空间
	//			throw;		//注意要向高层抛出异常
	//		}

	//		//析构并释放原 vector
	//		destroy(begin(), end());
	//		deallocate();

	//		//调整迭代器，指向新的 vector
<<<<<<< HEAD
=======
=======
	//			/* 鍏堝皢鍘焩ector涓� [start, pos) 鐨勫唴瀹规嫹璐濆埌 new_start 寮�濮嬬殑浣嶇疆 */
	//			new_finish = uninitialized_copy(start, pos, new_start);
	//			
	//			/* 鍦� new_finish(鍗硃os) 澶勬瀯閫犳彃鍏ョ殑鍏冪礌 x */
	//			construct(new_finish, x);
	//			++new_finish;		//璋冩暣姘翠綅

	//			/* 鍐嶅皢鍘焩ector涓� [pos, finish) 鐨勫唴瀹规嫹璐濆埌 new_finish 寮�濮嬬殑浣嶇疆 */
	//			new_finish = uninitialized_copy(pos, finish, new_finish);

	//			//鍏冪礌鎻掑叆瀹屾垚锛屾柊 vector 鏋勯�犲畬鎴�
	//		} catch (...) {
	//			//鎹曡幏鍒板紓甯革紝鎵ц鐩稿簲鐨勯攢姣佸伐浣溿�傛敞鎰忥細鍥犱负uninitialized_copy閬靛惊commit or rollback
	//			//鍘熷垯锛屾墍浠ユ瀯閫犲け璐ユ椂涓嶉渶瑕佽嚜宸辨墽琛屽璞￠攢姣佸伐浣滐紝鍙渶瑕侀噴鏀剧敵璇风殑鍐呭瓨灏卞ソ
	//			data_allocator::deallocate(new_start, new_capacity);		//閲婃斁绌洪棿
	//			throw;		//娉ㄦ剰瑕佸悜楂樺眰鎶涘嚭寮傚父
	//		}

	//		//鏋愭瀯骞堕噴鏀惧師 vector
	//		destroy(begin(), end());
	//		deallocate();

	//		//璋冩暣杩唬鍣紝鎸囧悜鏂扮殑 vector
>>>>>>> update
>>>>>>> update
	//		start = new_start;
	//		finish = new_finish;
	//		end_of_storage = new_start + new_capacity;
	//	}
	//}


<<<<<<< HEAD
	//内调函数，在pos处插入n个元素x，若空间不足进行扩容
=======
<<<<<<< HEAD
	//内调函数，在pos处插入n个元素x，若空间不足进行扩容
=======
	//鍐呰皟鍑芥暟锛屽湪pos澶勬彃鍏涓厓绱爔锛岃嫢绌洪棿涓嶈冻杩涜鎵╁
>>>>>>> update
>>>>>>> update
	template<class T, class Alloc>
	void vector<T, Alloc>::insert_aux(iterator pos, size_type n, const T& x) {
		if (n > 0)
		{
			if (size_type(end_of_storage - finish) >= n) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
				//备用空间大于等于新增元素个数
				T x_copy = x;
				
				//以下计算插入点之后的现有元素个数
				const size_type elems_after = finish - pos;
				iterator old_finish = finish;
				if (elems_after >= n) {		//插入点之后的元素个数大于等于新增元素个数
					uninitialized_copy(finish - n, finish, finish);		//在备用空间开始出再构造 n 个元素
					finish += n;		//将vector尾端标记后移
					copy_backward(pos, old_finish - n, old_finish);		//向后拷贝剩余元素，实现见 2stl_algobase.h
					//从插入点开始填入新值
					fill(pos, pos + n, x_copy);
				}
				else {		//插入点之后的元素个数小于新增元素个数
					uninitialized_fill_n(finish, n - elems_after, x_copy);	//现在finish之后构造n-elems_after个x_copy（因为插入之后这里就应该是x_copy）
					finish = finish + n - elems_after;
					uninitialized_copy(pos, old_finish, finish);	//将原本pos后的元素拷贝到插入之后正确的位置
<<<<<<< HEAD
=======
=======
				//澶囩敤绌洪棿澶т簬绛変簬鏂板鍏冪礌涓暟
				T x_copy = x;
				
				//浠ヤ笅璁＄畻鎻掑叆鐐逛箣鍚庣殑鐜版湁鍏冪礌涓暟
				const size_type elems_after = finish - pos;
				iterator old_finish = finish;
				if (elems_after >= n) {		//鎻掑叆鐐逛箣鍚庣殑鍏冪礌涓暟澶т簬绛変簬鏂板鍏冪礌涓暟
					uninitialized_copy(finish - n, finish, finish);		//鍦ㄥ鐢ㄧ┖闂村紑濮嬪嚭鍐嶆瀯閫� n 涓厓绱�
					finish += n;		//灏唙ector灏剧鏍囪鍚庣Щ
					copy_backward(pos, old_finish - n, old_finish);		//鍚戝悗鎷疯礉鍓╀綑鍏冪礌锛屽疄鐜拌 2stl_algobase.h
					//浠庢彃鍏ョ偣寮�濮嬪～鍏ユ柊鍊�
					fill(pos, pos + n, x_copy);
				}
				else {		//鎻掑叆鐐逛箣鍚庣殑鍏冪礌涓暟灏忎簬鏂板鍏冪礌涓暟
					uninitialized_fill_n(finish, n - elems_after, x_copy);	//鐜板湪finish涔嬪悗鏋勯�爊-elems_after涓獂_copy锛堝洜涓烘彃鍏ヤ箣鍚庤繖閲屽氨搴旇鏄痻_copy锛�
					finish = finish + n - elems_after;
					uninitialized_copy(pos, old_finish, finish);	//灏嗗師鏈琾os鍚庣殑鍏冪礌鎷疯礉鍒版彃鍏ヤ箣鍚庢纭殑浣嶇疆
>>>>>>> update
>>>>>>> update
					finish += elems_after;
					fill(pos, old_finish, x_copy);
				}
			}
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> update
			else {		//备用空间小于新增元素个数，必须配置额外的内存
				//首先决定新长度：旧长度的两倍或新插入元素长度的两倍
				const size_type old_capacity = capacity();
				const size_type new_capacity = 2 * max(old_capacity, n);

				//以下配置新的 vector 空间
				iterator new_start = data_allocator::allocate(new_capacity);
				iterator new_finish = new_start;
				try{
					//以下首先将旧 vector 中插入点之前的元素复制到新空间中
					new_finish = uninitialized_copy(start, pos, new_start);
					//再将新增元素 n 填入新空间
					new_finish = uninitialized_fill_n(new_finish, n, x);
					//最后将旧 vector 中插入点之后的元素移动到新空间
					new_finish = uninitialized_copy(pos, finish, new_finish);
				} catch (...) {
					//捕获到异常，执行相应的销毁工作。注意：因为uninitialized_copy、uninitialized_fill_n都遵循
					//commit or rollback原则，所以构造失败时不需要自己执行对象销毁工作，只需要释放申请的内存就好
					data_allocator::deallocate(new_start, new_capacity);
					throw;		//注意要向高层抛出异常
				}

				//析构并释放原 vector
				destroy(begin(), end());
				deallocate();

				//调整迭代器，指向新的 vector
<<<<<<< HEAD
=======
=======
			else {		//澶囩敤绌洪棿灏忎簬鏂板鍏冪礌涓暟锛屽繀椤婚厤缃澶栫殑鍐呭瓨
				//棣栧厛鍐冲畾鏂伴暱搴︼細鏃ч暱搴︾殑涓ゅ�嶆垨鏂版彃鍏ュ厓绱犻暱搴︾殑涓ゅ��
				const size_type old_capacity = capacity();
				const size_type new_capacity = 2 * max(old_capacity, n);

				//浠ヤ笅閰嶇疆鏂扮殑 vector 绌洪棿
				iterator new_start = data_allocator::allocate(new_capacity);
				iterator new_finish = new_start;
				try{
					//浠ヤ笅棣栧厛灏嗘棫 vector 涓彃鍏ョ偣涔嬪墠鐨勫厓绱犲鍒跺埌鏂扮┖闂翠腑
					new_finish = uninitialized_copy(start, pos, new_start);
					//鍐嶅皢鏂板鍏冪礌 n 濉叆鏂扮┖闂�
					new_finish = uninitialized_fill_n(new_finish, n, x);
					//鏈�鍚庡皢鏃� vector 涓彃鍏ョ偣涔嬪悗鐨勫厓绱犵Щ鍔ㄥ埌鏂扮┖闂�
					new_finish = uninitialized_copy(pos, finish, new_finish);
				} catch (...) {
					//鎹曡幏鍒板紓甯革紝鎵ц鐩稿簲鐨勯攢姣佸伐浣溿�傛敞鎰忥細鍥犱负uninitialized_copy銆乽ninitialized_fill_n閮介伒寰�
					//commit or rollback鍘熷垯锛屾墍浠ユ瀯閫犲け璐ユ椂涓嶉渶瑕佽嚜宸辨墽琛屽璞￠攢姣佸伐浣滐紝鍙渶瑕侀噴鏀剧敵璇风殑鍐呭瓨灏卞ソ
					data_allocator::deallocate(new_start, new_capacity);
					throw;		//娉ㄦ剰瑕佸悜楂樺眰鎶涘嚭寮傚父
				}

				//鏋愭瀯骞堕噴鏀惧師 vector
				destroy(begin(), end());
				deallocate();

				//璋冩暣杩唬鍣紝鎸囧悜鏂扮殑 vector
>>>>>>> update
>>>>>>> update
				start = new_start;
				finish = new_finish;
				end_of_storage = new_start + new_capacity;
			}
		}
	}

}// end of namespace lfp

#endif // !_STL_VECTOR_H_