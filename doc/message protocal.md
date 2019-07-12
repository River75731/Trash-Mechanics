## The Entire Process

#### e.g. User click a button in order to create a polygon, what's going on?

- #### The Windows layer activate a callback function

- #### 





# forget this now



# NO.1 Create Polygen

## User(View-to-Model) Command

### Command Name: CreatePolyCommand()

### Parameter Name: PolyParameter

### View Callback Function: onCreatePoly(Poly poly)

### View Binding Function: setCreatePolyCommand(...)

### ViewModel Expose Function: getCreatePolyCommand()

### ViewModel Control Model exec Function:

### execCreatePolyCommand(Poly)

### Model Data Update Function: createPoly(Poly)



## Inner(Model-to-View) Notification

### Notification(M2VM) Name: CreatePolyNotification()

### Parameter(M2VM) Name: PolyParameter

### M2VM Sender Name: mSendCreatePolyNotification()

### M2VM Receiver Name: vmGetCreatePolyNotification()

### Notification(VM2V) Name: CreatePolyNotification()

### Parameter(VM2V) Name: PolyParameter

### VM2V Sender Name: vmSendCreatePolyNotification()

### VM2V Receiver Name: vGetCreatePolyNotification()

### View Carryout Function Name: vExecCreatePolyNotification()