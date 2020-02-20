#ifndef _TV_H_
#define _TV_H_
//友元类：特定的类成员成为另一个类的友元
class Tv;
class Remote
{
private:
	enum State{ Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
private:
	int mode;
public:
	Remote(int m = TV) : mode(m) {}
	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t,int c);
};

class Tv
{
public:
	friend void Remote::set_chan(Tv & t,int c);
	enum State{ Off, On };
	enum { MinVal, MaxVal };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off,int mc = 125) : state(s),volume(5),
		maxchannel(mc),channel(2),mode(Cable),input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

inline bool Remote::volup(Tv & t) { return t.volup(); }
inline bool Remote::voldown(Tv & t) { return t.voldown(); }
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) { t.chanup(); }
inline void Remote::chandown(Tv & t) { t.chandown(); }
inline void Remote::set_mode(Tv & t) { t.set_mode(); }
inline void Remote::set_input(Tv & t) { t.set_input(); }
inline void Remote::set_chan(Tv & t,int c) { t.channel = c; }
//友元类：整个类成为友元
#if 0
class Tv
{
public:
	friend class Remote; //友元类
	enum{ Off, On };
	enum{ MinVal, MaxVal = 20 };
	enum{ Antenna, Cable };
	enum{ TV, DVD };

	Tv(int s = Off,int mc = 125) : state(s),volume(5),
		maxchannel(mc),channel(2),mode(Cable),input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t,int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
};
#endif
#endif