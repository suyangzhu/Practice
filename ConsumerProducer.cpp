int itemCount = 0;

procedure producer() {
	while(true) {
		item = produceItem();
		if (itemCount == BUFFERSIIZ) {
			sleep();
		}
		putItemIntoBuffer(item);
		itemCount++;
		if (itemCount == 1) {
			wakeup(consumer);
		}
	}
}

procedure consumer() {
	while(true) {
		if(itemCount == 0) {
			sleep();
		}
		item = removeItemFromBuffer();
		itemCount--;
		if (itemCount == BUFFER_SIZE-1) {
			wakeup(producer);
		}
		consumeItem(item);
	}
}

//////////////////////////////////////
//
//

semaphore: 

fillCount = 0;
emptyCount = BUFFER_SIZE;
procedure producer() {
	while(true) {
		item = produceItem();
		decrease(emptyCount);
		mutex_lock(mutex);
		putItemIntoBuffer(item);
		mutex_unlock(mutex);
		increase(fillCount)
	}
}

procedure consumer() {
	while(true) {
		decrease(fillCount) ;
		mutex_lock(mutex);
		item = removeItemFromBuffer();
		mutex_unlock(mutex);
		increase(emptyCount);
		consumerItem(item);
	}
}

