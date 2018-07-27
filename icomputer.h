using std::string;
using std::cout;
using std::endl; 
class IComputer
{
private:
	string m_strCpu;
	string m_strMainboard;
	string m_strRam;
	string m_strVideoCard;
public:
	class IComputerBuilder
	{
	private:
		IComputer *m_pComputer; 
	public:
		IComputerBuilder(IComputer *pComputer)
		{
			m_pComputer = pComputer;
		}
		virtual void setCpu()
		{
			setCpu("CPU");
		}
		virtual void setCpu(string cpu)
		{
			m_pComputer->m_strCpu = cpu;
		}
	//	virtual void setMainboard() = 0;
	//	virtual void setRam() = 0;
	//	virtual void setVideoCard() = 0;
	}; 
};
