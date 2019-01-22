// export const BaseUrl = "http://192.168.4.1:8000";
// export const BaseUrl = "http://192.168.43.190:8000";
// export const BaseUrl = "http://10.42.0.81:8000";


export function getBaseUrl() {
  return `${window.location.hostname}8000:`;
}
