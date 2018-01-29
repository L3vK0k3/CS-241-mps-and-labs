int test_camelCaser (char ** (* camelCaser)(const char *)){
	//make sure to add comments also
	//fck da police
    char *string = "The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.";
	char *str, = calloc(1,strlen(string) + 10);
	strcpy(str, string);
	char **camelCaseAnswer = camelCaser(str);
	char* one = "theHeisenbugIsAnIncredibleCreature", *two= "facenovelServersGetTheirPowerFromItsIndeterminism",
	*three="codeSmellCanBeIgnoredWithIncredibleUseOfAirFreshener", *four = "godObjectsAreTheNewReligion";
	int ans = 1;
	if(strlen(camelCaseAnswer)!=4) ans=0;
	if(strlen(camelCaseAnswer[0])!=34) ans=0;
	if(strlen(camelCaseAnswer[1])!=49) ans=0;
	if(strlen(camelCaseAnswer[2])!=52) ans=0;
	if(strlen(camelCaseAnswer[3])!=17) ans=0;

	if(strncmp(camelCaseAnswer[0], one, 34)) ans=0;
	if(strncmp(camelCaseAnswer[1], two, 49)) ans=0;
	if(strncmp(camelCaseAnswer[2], three, 52)) ans=0;
	if(strncmp(camelCaseAnswer[3], four, 27)) ans=0;
	//free the memmory :)
	for( i=0; i < strlen(camelCaseAnswer); i++){
		free(camelCaseAnswer[i]);
	}
	free(camelCaseAnswer);
	return ans;
}	