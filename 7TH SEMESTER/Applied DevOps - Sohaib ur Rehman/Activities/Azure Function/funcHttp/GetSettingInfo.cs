/*The following lines of code to add using directives for the
    Microsoft.AspNetCore.Http, Microsoft.AspNetCore.Mvc, and 
    Microsoft.Azure.WebJobs namespaces.*/
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Azure.WebJobs;

public static class GetSettingInfo
{
    [FunctionName("GetSettingInfo")]
    //Specify that the name of the Azure Function is "GetSettingInfo".
    public static IActionResult Run(
    [HttpTrigger("GET")] HttpRequest request,
    [Blob("content/settings.json")] string json)
    {
        string jsonString = @"{
        ""version"": ""0.2.4"",
        ""root"": ""/usr/libexec/mews_principal/"",
        ""device"": {
            ""id"": ""21e46d2b2b926cba031a23c6919""
        },
        ""notifications"": {
            ""email"": ""joseph.price@contoso.com"",
            ""phone"": ""(425) 555-0162 x4151""
        }
    }";
        return new OkObjectResult(jsonString);
    }

    /*The following code to update the Run expression-bodied method
     to return a new instance of the OkObjectResult class passing 
     in the value of the json method parameter as the sole 
     constructor parameter.*/
}