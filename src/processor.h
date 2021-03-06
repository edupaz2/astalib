#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include "astalib_defs.h"
#include <boost/fiber/buffered_channel.hpp>

class Processor
{
public:
	virtual 		~Processor();

	void			init		();
	void			done		();

    task_id 		startTask	();
	task_id 		startTask	(const task_type& type);

	task_id			pauseTask	(const task_id& id);
	task_id			resumeTask	(const task_id& id);
	task_id			stopTask	(const task_id& id);

	task_status		status 		();

	void			quit		();

private:
	typedef std::function<void()> Task;
	typedef boost::fibers::buffered_channel<Task> Channel;
	Channel* 	 m_channel;
	std::thread* m_worker;
};

#endif