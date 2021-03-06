Main()
{

	// to denote which thread will enter next
	int favouredthread = 1;

	// flags to indicate if each thread is in
	// queue to enter its critical section
	boolean thread1wantstoenter = false;
	boolean thread2wantstoenter = false;

	startThreads();
}

Thread1()
{
	do {

		thread1wantstoenter = true;

		// entry section
		// wait until thread2 wants to enter
		// its critical section
		while (thread2wantstoenter == true) {

			// if 2nd thread is more favored
			if (favaouredthread == 2) {

				// gives access to other thread
				thread1wantstoenter = false;

				// wait until this thread is favored
				while (favouredthread == 2)
					;

				thread1wantstoenter = true;
			}
		}

		// critical section

		// favor the 2nd thread
		favouredthread = 2;

		// exit section
		// indicate thread1 has completed
		// its critical section
		thread1wantstoenter = false;

		// remainder section

	} while (completed == false)
}

Thread2()
{

	do {

		thread2wantstoenter = true;

		// entry section
		// wait until thread1 wants to enter
		// its critical section
		while (thread1wantstoenter == true) {

			// if 1st thread is more favored
			if (favaouredthread == 1) {

				// gives access to other thread
				thread2wantstoenter = false;

				// wait until this thread is favored
				while (favouredthread == 1)
					;

				thread2wantstoenter = true;
			}
		}

		// critical section

		// favour the 1st thread
		favouredthread = 1;

		// exit section
		// indicate thread2 has completed
		// its critical section
		thread2wantstoenter = false;

		// remainder section

	} while (completed == false)
}
