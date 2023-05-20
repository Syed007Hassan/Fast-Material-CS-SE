@extends('customers.layout')

@section('content')
    <div class="row">
        <div class="col-lg-12 mb-4 mt-5 ">
            <div class="d-flex justify-content-between align-items-center">
                <h2 class="fs-3 mb-0">Customer Data</h2>
                <a class="btn btn-primary" href="{{ route('customers.create') }}">Create New Customer</a>
            </div>
        </div>
    </div>

    @if ($message = Session::get('success'))
        <div class="alert alert-success alert-dismissible fade show" role="alert">
            <p class="mb-0">{{ $message }}</p>
            <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
        </div>
    @endif

    <div class="table-responsive">
        <table class="table table-hover table-bordered">
            <thead>
                <tr class="table-dark">
                    <th scope="col">ID</th>
                    <th scope="col">Name</th>
                    <th scope="col">Email</th>
                    <th scope="col">City</th>
                    <th scope="col">RoomType</th>
                    <th scope="col" width="200px">Action</th>
                </tr>
            </thead>
            <tbody>
                @foreach ($customers as $customer)
                    <tr>
                        <th scope="row">{{ $customer->id }}</th>
                        <td>{{ $customer->name }}</td>
                        <td>{{ $customer->email }}</td>
                        <td>{{ $customer->city }}</td>
                        <td>{{ $customer->roomType }}</td>
                        <td>
                            <form action="{{ route('customers.destroy', $customer->id) }}" method="POST">
                                <div class="btn-group" role="group">
                                    <a class="btn btn-sm btn-primary"
                                        href="{{ route('customers.show', $customer->id) }}">Show</a>
                                    <a class="btn btn-sm btn-success"
                                        href="{{ route('customers.edit', $customer->id) }}">Edit</a>
                                    @csrf
                                    @method('DELETE')
                                    <button type="submit" class="btn btn-sm btn-danger">Delete</button>
                                </div>
                            </form>
                        </td>
                    </tr>
                @endforeach
            </tbody>
        </table>
    </div>

    {!! $customers->links('pagination::bootstrap-5') !!}
@endsection
